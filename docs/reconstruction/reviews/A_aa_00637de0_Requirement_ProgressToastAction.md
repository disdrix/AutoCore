# Review A (reconstruction fidelity): `aa_00637de0` shared progress toast Action

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637de0` |
| **VA** | `0x00637de0` |
| **Canonical name** | `FUN_00637de0` (role: **Requirement progress toast Action**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00637de0_Requirement_ProgressToastAction.md` |
| **System tag** | `missions-progression` |
| **Scope** | Dual A/B only — no WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00637de0_FUN_00637de0.md` |
| Annotated | `docs/reconstruction/raw/aa_00637de0_FUN_00637de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00637de0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00637de0_FUN_00637de0.md` |
| Caller residual | `docs/reconstruction/reviews/a_00809460.md` (`Client_RecvObjectiveState`) |
| Live Ghidra | decompile `0x00637de0`, `read_memory` body + vtbl slots + globals, xrefs |

---

## 2. Purpose (sealed role)

Shared requirement virtual at **`vtbl+0x20`**, invoked by `Client_RecvObjectiveState` (`0x00809460`) for each set bit of the progress mask after S2C `0x2071` slot writes. Builds progress text via **`vtbl+0x1c`** (usually trampoline `0x00637dd0` → SlotAction at `+0x18`) and enqueues a **0x98-byte** UI toast element through `FUN_0040c5c0`. Skips when requirement type dword at `req+0x0c` is **7** or **8** (product `RequirementType` Km / TimePlayed). Does **not** mutate slots, complete objectives, or call `EvaluatePendingObjectives`.

---

## 3. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| `thiscall(req, character, stateNode*)` | **High** | Prologue ECX=req; stack args loaded into ESI/EDI; `ret 8` |
| Early-out `req+0x0c ∈ {7,8}` | **High** | Bytes `mov eax,[ecx+0xc]; cmp 8/7; je exit` |
| `vtbl+0x1c(char, state, buf, 0x7f)` fills toast string | **High** | `push 0x7f; lea buf; push char; push state; call [eax+0x1c]` |
| `+0x1c` trampoline `0x00637dd0` = `jmp [vtbl+0x18]` | **High** | Bytes `8B 01 FF 60 18` at `0x00637dd0`; UseItem/Collect/Patrol/Kill install it |
| Color `0xffeee3d8` | **High** | Byte stores D8/E3/EE + BL=FF; same as GiveMission toast |
| Scale float **2.0** from `0x00a10e74` | **High** | `read_memory` `00 00 00 40`; decomp symbol `g_flLevelUpUiBase_Inferred` (shared misnomer) |
| Second float **1.5** from `DAT_00aaa68c` | **High** | `read_memory` `00 00 c0 3f` |
| Entity TFID from `*stateNode+0x10` (sign-extend to i64) or −1 | **High** | `cdq` after load; null/zero-deref → −1/−1 |
| `FUN_0040c5c0` = growable vector push, elem **0x98** | **High** | Callee body; GiveMission/CompleteObjective same queue recipe |
| Toast queue this: `*(*(X+4) + charBase + 0xA8) + 0xE8C8` | **High** (addressing) | Asm in this unit + GiveMission + CompleteObjective |
| Shared `vtbl+0x20` across requirement classes | **High** | 14 DATA xrefs; sampled UseItem/Collect/Patrol/Kill all `+0x20 → 0x00637de0` |
| Not Eval / not event Action / not SlotAction | **High** | Slot map: Eval `+0x08`/`+0x10`, event Action `+0x04`, SlotAction `+0x18` |
| Types 7/8 = Km / TimePlayed | **Probable** | Matches AutoCore `RequirementType` enum; client dword not re-proven against RTTI here |
| Original PDB name | Open | — |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

```
entry (thiscall ECX=req)
  type = req[+0x0c]
  if type == 8 || type == 7: return
  buf[0] = 0
  req->vtbl[+0x1c](character, stateNode, buf, 0x7f)
  pack toast:
    color = 0xffeee3d8
    scale = *(float*)0x00a10e74          // 2.0
    field  = *(float*)0x00aaa68c         // 1.5
    zero   = 0
    if !stateNode || !*stateNode:
      id64 = -1
    else:
      id64 = sign_extend(*(int*)(*stateNode + 0x10))
  FUN_0040c5c0(toastQueue, &toastElement)  // thiscall; elem size 0x98
  return
```

| Stage | Match |
|---|---|
| Type 7/8 skip | **Yes** |
| `+0x1c` text fill | **Yes** |
| Color / 2.0 / 1.5 / zero | **Yes** |
| TFID from `*state+0x10` | **Yes** |
| Enqueue `FUN_0040c5c0` only callee | **Yes** |
| No slot write / no Complete / no EvaluatePending | **Yes** |

---

## 5. Cross-type vtable seal (sampled)

| Class | Vtbl base | `+0x18` SlotAction | `+0x1c` | **`+0x20` toast** |
|---|---|---|---|---|
| UseItem | `0x009dfc1c` | `0x0060d060` | `0x00637dd0` | **`0x00637de0`** |
| Collect | `0x009e12c4` | `0x006124b0` | `0x00637dd0` | **`0x00637de0`** |
| Patrol | `0x009e0404` | local | `0x00637dd0` | **`0x00637de0`** |
| Kill | `0x009e19e4` | local | `0x00637dd0` | **`0x00637de0`** |

DATA xrefs to `0x00637de0` (all vtbl +0x20 samples):  
`009df724`, `009dfab4`, `009dfc3c`, `009e0424`, `009e0694`, `009e08ec`, `009e0b8c`, `009e0cac`, `009e0e24`, `009e0f44`, `009e12e4`, `009e1874`, `009e1a04`, `009e3bcc` + one code site `005aded2` (function not defined in Ghidra).

---

## 6. Gaps (accept)

1. Product / PDB name for this Action and for `FUN_0040c5c0`.
2. Semantic names of toast fields after the string (2.0 scale vs duration; 1.5 secondary scale) — values sealed, UI meaning open.
3. Exact owner object of toast queue (`+0xA8` / `+0xE8C8` chain) — addressing sealed, class name open.
4. Code caller at `0x005aded2` (undefined function in Ghidra).
5. Runtime / bit-exact / image diff (project-wide open).
6. Whether every requirement class with a vtbl uses this toast (14 DATA xrefs; not every RTTI name mapped).

**Verdict:** static dual fidelity **sealed** for role + CF + constants. **accept-with-gaps.**
