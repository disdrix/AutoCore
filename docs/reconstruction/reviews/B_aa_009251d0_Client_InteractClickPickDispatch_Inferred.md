# Review B (skeptical / adversarial): `aa_009251d0` Client_InteractClickPickDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009251d0` |
| **VA** | `0x009251d0` |
| **Canonical name** | `Client_InteractClickPickDispatch_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-038 OWN dual) |
| **Counterpart** | `reviews/A_aa_009251d0_Client_InteractClickPickDispatch_Inferred.md` |
| **System** | `interaction-activation` |
| **Live tools** | Ghidra `decompile_function` + `disassemble_function` + `read_memory` + xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same function as `Client_InteractClickPickTarget` | Different VA; no 25f gate / SendUseObject / type-switch; only **calls** parent | **Falsified** alias |
| 2 | Same as `Client_InteractWorldClickHub` | Neighbor vtable slot only; no ItemPickup `0x2055`, no 100f/20f gather | **Falsified** alias |
| 3 | Always sends UseObject | Body never calls SendUseObject / IfInteractable; parent may | **Falsified** always-send |
| 4 | Mode-6 enables click body | Asm: mode==6 **and** quiet flags → **return 0** (swallow) | **Falsified** inverted gate |
| 5 | Soft when `DAT_00d1a860==0` | Asm: `JNZ` soft (`PUSH 0`) when flag **≠0**; commit when **==0** | **Falsified** inverted soft |
| 6 | `RET 4` / zero stack args | Epilogue `C2 08 00`; two stack formals used | **Falsified** |
| 7 | Direct multi-callers | Only DATA `@ 0x00a2f41c` | **Falsified** as direct CALL graph |
| 8 | `unaff_EBX` is a mystery third arg | `MOV EBX,ECX` this; parent residual uses EBX as client | **Falsified** mystery-arg |
| 9 | Decompiler drops stack arg1 | Asm loads ESI from stack; pushes to consume + ClickPickTarget | **Falsified** “unused param_2” |
| 10 | Soft path returns pick result | Soft arm always `XOR AL,AL` / return 0 after optional HB | **Falsified** “return pick AL on soft” |
| 11 | Product method name proven | Structural `_Inferred` only | **Agree Open/Probable** |
| 12 | Scaffold invents stages | Live ≡ raw; asm seals soft/commit + RET 8 | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stage order + soft/commit branch | **High** | Wrong interact input port |
| ABI thiscall + RET 8 + packed mouse | **Confirmed** | Wrong hook signature |
| Skill cancel on pending skill | **Confirmed** | Sticky target-select chrome |
| `DAT_00d1a859` write polarity | **Confirmed** | Soft-select free flag inverted |
| Distinct from parent UseObject hub | **High** | Double-count UseObject ownership |
| Distinct from sibling WorldClickHub | **High** | Wrong ItemPickup/soft-cast routing |
| Vtbl English / mode 6 product | **Open** | Docs only |
| Which UI event fires this slot | **Open** | Wrong “when does this fire” narrative |
| Runtime | **Open** | Doc vs live |

---

## 3. Cross-check traps

### Gate polarity trap

```
cmp [ebx+0xcc4], 6 ; jnz body
cmp byte [ebx+0x493], 0 ; jnz body
cmp byte [world+0xf5], 0 ; jnz body
; else return 0
```

**Only** the triple-quiet mode-6 case skips the hub. Do not document as “mode 6 enables interact.”

### Soft/commit trap

Parent dual residual: soft gather when `param_3==0`. This unit:

| `DAT_00d1a860` | Push | Path |
|---|---:|---|
| ≠ 0 | **0** | soft + optional HB; **return 0** |
| == 0 | **1** | commit; **return pick AL** |

Do not invert from DriveControlTick comments without re-reading this body.

### Soft return trap

Soft path **discards** ClickPickTarget return and forces **0**. Commit path propagates AL. Ports that always return pick result are wrong.

### Skill-cancel trap

Cancel runs **before** character/UI gates when `DAT_00d1d900 != -1`, and returns **1** without calling ClickPickTarget. Click during pending skill target-select aborts chrome; it does not interact-pick.

### Sibling merge trap

| Unit | Vtable | Primary outcome |
|------|--------|-----------------|
| This | `0x00a2f41c` | → ClickPickTarget → UseObject chain |
| WorldClickHub | `0x00a2f420` | ItemPickup / soft-cast / destroy modal |

Do not merge.

### `unaff_EBX` trap

Decompiler invents `unaff_EBX` at ClickPickTarget sites. Asm: **EBX = this** for entire body. Parent dual already treats EBX as client residual at its call sites.

---

## 4. Surviving contract for AutoCore

```
Client_InteractClickPickDispatch_Inferred(client, arg1, packedMouse) -> bool:
  if mode==6 and !flag493 and !worldF5: return 0
  mouse vtbls on select(+0x4b8)
  if select and select.vtbl+0x378(arg1, packed): return 1
  if pendingSkill != -1: PromptSkillTargetSelect(-1,0); postCancelUI; return 1
  if !character or dead or UI modals: return 0
  DAT_00d1a859 = freePredicate && !char.cd0 && optionalUI.idle
  if softFlag DAT_00d1a860:
      ClickPickTarget(arg1, packed, 0, filter)
      maybe HB_Start; return 0
  return ClickPickTarget(arg1, packed, 1, filter)

AutoCore must NOT:
  - treat this as the 25f UseObject owner (parent does that)
  - merge with WorldClickHub ItemPickup path
  - invert soft/commit relative to DAT_00d1a860
  - assume direct non-virtual callers
  - drop stack arg1 or claim RET 0/4
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Multi-stage click dispatch | **Agree High** |
| ABI / soft-commit Confirmed | **Agree Confirmed** |
| Skill cancel Confirmed | **Agree Confirmed** |
| accept-with-gaps | **Agree** (English + runtime + arg1 product) |
| Distinct from parent + sibling | **Agree High** |
| Name `_Inferred` | **Agree Probable** — not product PDB |

---

## 6. Open questions

1. Product name for the vtable method / mode 6 / soft flag.
2. Live event that indexes slot `@ 0x00a2f41c`.
3. Exact product type of stack `arg1`.
4. Dual of `FUN_00914be0` / `FUN_007fb990` (out of OWN).

**Verdict:** **accept-with-gaps** — adversarial pass on CF/ABI; residual is naming/runtime/sub-callees.
