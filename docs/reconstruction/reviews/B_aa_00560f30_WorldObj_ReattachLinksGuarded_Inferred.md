# Review B (skeptical / adversarial): `aa_00560f30` WorldObj_ReattachLinksGuarded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560f30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-O) |
| **Counterpart** | `reviews/A_aa_00560f30_WorldObj_ReattachLinksGuarded_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + call-site context. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler surface is full ABI (`void FUN(…)` without ret width) | **Partial** — signature needs **`ret 4`**; ECX=manager confirmed |
| 2 | This is full enroll (`00560ec0`) | **Falsified** — no `+0x130/+0x134` counters, no refcount at `obj+6`, no `0062a450` notify |
| 3 | This is `WorldObj_RebindActivate` (`00560e90`) | **Falsified** — uses `0055e760` not unbind `0055fbf0`; no `*(obj+0x44)+0x28=1`; **`ret 4`** not `ret 8` |
| 4 | Call order is bind then attach | **Falsified** — `0055e760` first, then `0055fa40` |
| 5 | Flag is on the object | **Falsified** — flag is **manager** `+0x12c` |
| 6 | Multiple callers beyond SwitchHBAI | **Falsified** — **1** UNCONDITIONAL_CALL from `005d4440` |
| 7 | Function returns status in EAX | **Falsified** — void; no status idiom |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag + attach + bind CF | **High** | Wrong lifecycle port |
| Manager thiscall + ret 4 | **High** | Stack bugs |
| Distinction from enroll / RebindActivate | **High** | Wrong sibling used after mode switch |
| Product class / mode-7 English | Medium | Naming only |
| `0055e760` internals | Out of scope | Must not invent attach rules here |

---

## 3. Cross-check against raw + bytes + call site

```
; 005d4440 site when new mode == 7:
PUSH ESI          ; obj
MOV  ECX, EDI     ; manager
CALL 00560f30     ; ret 4 cleans one stack dword
```

Body never reads a second formal. Clean must **not** invent enroll counters, unbind path, or host `+0x28` flag write.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (world/phys manager) — mode-enter-7 reattach
void WorldObj_ReattachLinksGuarded(Manager mgr, WorldObj obj)
{
    byte prev = mgr.FlagAt0x12c;
    mgr.FlagAt0x12c = 1;
    AttachRegister(mgr, obj);  // FUN_0055e760
    BindLinks(mgr, obj);       // FUN_0055fa40
    mgr.FlagAt0x12c = prev;
}
// Not enroll. Not unbind+rebind+host-flag (00560e90).
```

---

## 5. Open questions

1. Whether server-side mode transitions need the same guarded reattach.
2. Interaction of `+0x12c` with deferred remove (`00561450` family).
3. Dual seal of `0055e760` when scheduled.

**Verdict:** **accept**
