# Review B (skeptical / adversarial): `aa_00437150` RefCountedSlot_ReleaseAndClear

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00437150_RefCountedSlot_ReleaseAndClear.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__cdecl` / no stack cleanup | Epilogue **`C2 04 00`** | **Falsified** — **stdcall RET 4** |
| 2 | Releases two different slots | Both phases use same ESI/`[ESI]` | **Falsified** — **one slot** |
| 3 | Double-decrements live objects always | Phase1 clears; phase2 re-reads null | **Falsified** for normal CF — **single effective release** |
| 4 | Is pure COM `IUnknown::Release` only | Call is vtbl+8 with custom layout (+4 refcount, not COM's at +8) | **Partial** — **COM-like** but **intrusive +4**, not assuming IUnknown layout |
| 5 | thiscall on helper itself | No ECX use for slot; ESI holds slot ptr | **Falsified** — **stdcall slot\*\*** |
| 6 | Name must be phy-CP-only | Xrefs include Unwind@*, FUN_00439f00, non-CP sites | **Falsify exclusive** — generic slot helper |
| 7 | Decompiler void return hides EAX | No MOV to EAX on success paths | **Confirmed** void |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall + RET 4 | **High** | Stack imbalance |
| refcount @+4, destroy vtbl+8 | **High** | UAF / leak |
| *slot = 0 after phase1 | **High** | Double-free at callers |
| Phase2 residual | **High** | Overstated dual-release ports |
| Held type product identity | **Low–Medium** | Wrong class docs |
| SEH necessity in ports | **Medium** | Server can omit FS:[0] if no EH |

---

## 3. Cross-check against raw + bytes

```
raw decompile:
  if (*slot) { --ref@+4; if0 vtbl+8; *slot=0; }
  if (*slot) { --ref@+4; if0 vtbl+8; }   // residual

bytes @ 00437150:
  64A1... SEH  56 8B742414  C744240C00000000
  8B0E 85C9 7411  834104FF 7505 8B01 FF5008  C70600000000
  C744240CFFFFFFFF  8B0E 85C9 740B  834104FF 7505 8B11 FF5208
  ... 83C40C C20400

≡ same CF. Call sites PUSH slot / CALL; CP pair dual already notes no-op when null.
```

---

## 4. Surviving contract for AutoCore

```csharp
// Intrusive refcount slot clear (client helper). Prefer IDisposable / SafeHandle on server.
void RefCountedSlotReleaseAndClear(ref object? slot)
{
    var obj = slot;
    if (obj == null) return;
    // client: --obj.RefCount@+4; if 0 → vtbl+8 destroy; slot = null
    slot = null; // after release
}
```

- Do **not** implement phase2 as a second live release in ports.  
- Callers that already null/release then call this helper are **safe** (no-op).  
- SEH frame is retail MSVC EH, not game logic.

---

## 5. Open questions

1. Shared base class / RTTI for held objects.  
2. Exact destroy semantics of vtbl+8.  
3. Whether any caller relies on phase2 (none found under clear).  
4. Runtime confirmation.  
5. Relationship to other ReleaseClear helpers in COM/BSTR family (naming only).

**Verdict:** **accept**
