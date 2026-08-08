# Review B (adversarial): `aa_0060df70` CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060df70` |
| **VA** | `0x0060df70`–`0x0060e06a` (**251 B** / `0xFB`) |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` |
| **Ghidra name** | `FUN_0060df70` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Adversarial / claim-falsification (OWN-ONLY MEGA-038) |
| **Counterpart** | `reviews/A_aa_0060df70_CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.md` |
| **System** | missions-progression |
| **Evidence pass** | Same live Ghidra surface as Path A; challenge naming, arity, return semantics, class binding. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Attack surface (claims to falsify)

| # | Claim under test | Result |
|---:|---|---|
| 1 | This is MatchTarget itself / Eval body | **Falsified** — Match is `0060d460`; Eval is vtbl+8 `0060cfe0`; this only *calls* them |
| 2 | Direct code callers exist | **Falsified** — callers empty; only DATA vtbl `009dfc20` |
| 3 | Decompiler 5-arg stack is complete ABI | **Falsified** — image `RET 0x1C` = 7 dwords; worldObj at entry+0x1C |
| 4 | Packet arm returns Apply-like success | **Falsified** — after `FUN_005319d0`, fallthrough `XOR AL,AL` always 0 |
| 5 | Event filter is soft / many event ids | **Falsified** — hard `CMP 9` / `CMP 0xA` only |
| 6 | `req+0x34` means inventory CBID | **Falsified** — used only as zero/nonzero branch; CBIDs live elsewhere on Apply/Match |
| 7 | Class is generic ObjectiveRequirement (not UseItem) | **Falsified** — vtbl `009dfc1c` shared with dualed UseItem Eval/Apply/Match/Serialize; Apply path RTTI-cast UseItem in `FUN_005319d0` |
| 8 | Name can drop `_Inferred` (product-sealed) | **Not sealed** — event 9/10 English + packet helper product name open → keep `_Inferred` |
| 9 | Scaffold `Named_CalleeOf_*` is correct final name | **N/A / retired** — no such scaffold for this VA; named clean is ObjectEventDispatch_Inferred |

---

## 2. Residual risks (not falsified — remain gaps)

1. **Event taxonomy:** 9 vs 10 product meaning unknown; both share Match path.
2. **`FUN_005319d0`:** body shows local gate + dynamic_cast UseItem + LogicUi packet `0xE`; full network/UI product name open.
3. **Unread args:** three stack dwords cleaned but never loaded — base virtual signature likely wider than this override uses.
4. **Return-0 after packet:** may be intentional “consume event / no further base handling” — not proven at runtime.
5. **No runtime Confirmed** (Launcher forbidden this wave).

---

## 3. ABI adversarial check

| Check | Evidence | Pass |
|---|---|---|
| thiscall ECX | `8B F1` early | **Yes** |
| RET 0x1C both exits | `C2 1C 00` @ `e055` and `e06a` | **Yes** |
| Apply path preserves AL | no `XOR AL` between `CALL 0060d630` and ret | **Yes** |
| Fail path clears AL | `32 C0` @ `e04f` | **Yes** |
| Body length | next non-body `CC` pad @ `e06b` | **Yes** (251 B) |

---

## 4. Naming adversarial check

| Candidate | Why reject / accept |
|---|---|
| `FUN_0060df70` | Ghidra only; keep twin |
| `UseItem_MatchTarget` | Wrong body — Match is `0060d460` |
| `UseItem_ApplyObjectUseProgress` | Wrong body — Apply is `0060d630`; this *dispatches to* it |
| `Named_CalleeOf_Apply...` | Scaffold style; retire in favor of role name |
| `..._ObjectEventDispatch_Inferred` | **Accept** — role sealed; product residual → `_Inferred` |

---

## 5. Verdict

Path B could **not** break CF, ABI RET0x1C, event gate, Match/Apply branch, or UseItem vtbl binding. Product gaps remain on event English and packet helper. **accept-with-gaps** (aligned with Path A).
