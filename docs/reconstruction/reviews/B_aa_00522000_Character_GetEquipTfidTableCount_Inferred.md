# Review B (skeptical / adversarial): `aa_00522000` Character_GetEquipTfidTableCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522000` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Agent** | MEGA-100 OWN-ONLY |
| **Counterpart** | `reviews/A_aa_00522000_Character_GetEquipTfidTableCount_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Mission / objective UI helper (Named_CalleeOf scaffold) | Scaffold parent chain only; body is pure equip-count math | **Falsified** — retire scaffold name |
| 2 | Static / no-this; uses global only | Bytes load `[ECX+0x59a]`; callers set ECX | **Falsified** — thiscall ECX required |
| 3 | Decompiler `__fastcall int param_1` is full story without this | Same as ECX this; listing `undefined(void)` is wrong | **Falsified as void** — EAX live count |
| 4 | Count is plain `*(+0x59a)` or `+0x59a + 3` without shift | Bytes `SHR 1` then `ADD 3` | **Falsified** — must keep `>>1` |
| 5 | Clamp max is 7 (decompiler `7 <` misread) | `cmp eax,8` / `jl` / `mov eax,8` | **Falsified as max-7** — clamp **at 8** |
| 6 | Stack arg / `RET 4` | Epilogue is bare `C3`; no stack loads | **Falsified** |
| 7 | Mutates character / table | No stores in body | **Falsified** — pure read |
| 8 | Cargo / locker grid capacity | Callers index `+0x5a0` equip TFID pairs, not grid | **Falsified as grid-count** |
| 9 | Sibling `FUN_00522020` is same unit | Separate body @ `00522020` (mode-select inventory grid) | **Distinct** |
| 10 | Product name final without `_Inferred` | No string/RTTI plate | **Gap** — keep `_Inferred` |
| 11 | Always returns ≥3 for any this | True only if `+0x59a` present; null this is caller-guarded | **Survives under non-null this** |

---

## 2. Residual risks

| Risk | If wrong | Mitigation |
|---|---|---|
| `+0x59a` not equip-related | Wrong field English | Multi-caller equip table use; SetLevelWithFlags also writes it — English still open |
| Table hard capacity ≠ 8 | Over-scan / under-scan | Clamp + UI null-path literal 8 agree |
| Signed `JL` on huge count | Weird clamp for pathological `+0x59a` | Field is uint8; after >>1+3 max 130 → still clamps to 8 |
| Orphan xrefs not in function bounds | Missed caller semantics | `read_memory` still shows same ECX global + call |

---

## 3. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / formula / ABI | **Confirmed** | Port wrong slot counts |
| Equip-table role | **High** | Mis-name only |
| `+0x59a` product English | **Open** | Registry rename later |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```text
// __thiscall Character* this; bare RET
// EAX = min(8, (*(uint8_t*)(this + 0x59a) >> 1) + 3)
// Leaf. No stack args. No mutation.
// Callers: equip TFID scan bound for this+0x5a0 (stride 8).
uint8_t Character_GetEquipTfidTableCount_Inferred(Character* this);
```

**Reject as canonical:** `Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_00522000`.

**Verdict:** **accept.**
