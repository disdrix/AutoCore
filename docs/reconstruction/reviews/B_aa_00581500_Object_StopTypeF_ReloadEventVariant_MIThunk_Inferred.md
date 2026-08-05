# Review B (skeptical / adversarial): `aa_00581500` Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00581500` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-O dual B) |
| **Counterpart** | `reviews/A_aa_00581500_Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_00581500.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Body is pure `call impl; ret` with no adjust | **Falsified** — bytes show `-0x8C` / `+4` LEA path |
| 2 | Plain `ret` / cdecl | **Falsified** — `C2 04 00` |
| 3 | Decompiler `void FUN…(void)` is full ABI | **Overstated** — missing thiscall + stack dword |
| 4 | Multiple direct CALL factories | **Falsified** — sole CALL `FUN_005d49e0`; others JMP adjustors |
| 5 | Thunk implements type-0xF stop logic | **Falsified** — all work in `0x00514d80` |
| 6 | Product name confirmed | **Overstated** — structural from W28-H impl |
| 7 | `ret 4` means impl takes one meaningful arg | **Clarify** — impl uses plain ret; dword is virtual ABI cleanup |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / adjust / call target / ret 4 | **High** | ABI break / wrong this |
| Sole CALL + JMP-peer model | **High** | Wrong caller model |
| Product spelling | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw decompile: FUN_00514d80(); return;   // incomplete surface
bytes: 8B 81 74FFFFFF  8B 50 04  8D 8C 0A 74FFFFFF  E8→00514d80  C2 04 00  CC…
```

Clean **must**:
- perform this-adjust before call,
- preserve `ret 4`,
- not inline type-0xF walk / LoadEvent logic,
- not invent null checks.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_00581500 — Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred
// thiscall: this=ECX (subobject). ret 4. void.
unsafe void MIThunk(void* selfSub)
{
    void* p = *(void**)((byte*)selfSub - 0x8C);
    int delta = *(int*)((byte*)p + 4);
    void* selfObj = (byte*)selfSub + delta - 0x8C;
    Object_StopTypeF_ReloadEventVariant_Inferred(selfObj);
}
```

---

## 5. Verdict

Adversarial pass **confirms** A on bytes/ABI/callee; product spelling remains `_Inferred` only → **accept**.
