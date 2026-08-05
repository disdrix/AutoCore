# Review A (reconstruction fidelity): `aa_009247b0` Client_InteractClickPickTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_009247b0` |
| **VA** | `0x009247b0` |
| **Canonical name** | `Client_InteractClickPickTarget` |
| **Review date** | `2026-07-29` (dual residual strengthen 25f/0.015f; prior refresh same day / 2026-07-23) |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_009247b0_Client_InteractClickPickTarget.md` |
| **Residual seal** | `reviews/a_009247b0.md` |
| **System** | `interaction-activation` |
| **Verdict** | **accept-with-gaps** (UseObject gate + ECX + constant table **High**; helper names residual) |

---

## 1. Purpose

Click/pick **hub** that:

1. Early-outs on modal / mode flags.
2. Resolves a world object (primary `FUN_00490070`, else soft ray + gather paths).
3. Stores selection on client slots `[0x349]` (`+0xd24`) and `[0x1d6]` (`+0x758`).
4. May call **`Client_SendUseObject_IfInteractable`** when `FUN_005245d0` or `FUN_00524520` returns non-zero.
5. May call **`Client_SendUseObject`** when selected `obj+0x11c != 0` and Euclidean distance to player body ≤ **`DAT_00aaa6fc` = 25.0f**.
6. Runs a clone-type switch (secondary actions); type **4** sends **QuestItemPickup `0x205D`** size `0x10`.

This is the primary **producer** of C2S UseObject (`0x2072`) from mouse click/pick (alongside bound-action poll).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009247b0_Client_InteractClickPickTarget.md` (+ 2026-07-29 version note) |
| Annotated | `docs/reconstruction/raw/aa_009247b0_Client_InteractClickPickTarget.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InteractClickPickTarget.cpp` |
| Function record | `docs/reconstruction/functions/aa_009247b0_Client_InteractClickPickTarget.md` |
| Live decompile | Ghidra `batch_decompile` `0x009247b0` (2026-07-29) ≡ raw body |
| Caller | `FUN_009251d0` live decompile (soft `param_3=0` / commit `1`) |
| Callees sealed | `aa_00916740` SendUseObject; `aa_00930d70` IfInteractable; `aa_00524520` FindActiveObjectiveId |
| Memory | `read_memory` range DATs (25 / 0.015 / 10 / 5 / 40) — re-check residual pass |
| Asm | `get_assembly_context` matcher calls + UseObject FPU + gather scales |
| Residual | `reviews/a_009247b0.md` (25f/0.015f + ECX + modes) |
| Chain | `reviews/CHAIN_2026-07-29_interaction_useobject.md` |
| Product | `NpcInteractHandler` 30f vs client 25f comment |
| Gather modes | sealed via `aa_0058d330` (mode 3 soft A; mode 2 soft B) |

---

## 3. Control flow (authoritative raw / live)

```
clear select[0x349]
if modal(+0x4f1) or !vtbl+0x3d8: return 0
if DAT_00d1a8da: camera pick → FUN_0093e120(select); return 1   // no UseObject
piVar4 = FUN_00490070(...)
if piVar4==0 and !block:
  if param_3==0:
    screen→world; ray 400; if miss return 1
    scale = FUN_0040d020(hit - cam) * 0.015f          // DAT_00aaacbc
    gather radius = scale*10 cap 25; mode=3 max=1     // living interact
    if empty TFID: radius = scale*5 cap 25; FUN_0058cd60 (…,1,5,…); maybe resolve
    else: resolve; type 0x12 only if vtbl+0x1d8 + FUN_0040b1b0
  if still 0:
    gather radius = scale*25 cap 40; mode=2 max=1     // hostile filter path
if (char)param_4==0 and (pick==self or pick==vehicle): return 1
store select[0x349=+0xd24],[0x1d6=+0x758]
if pick:
  // ECX = DAT_00d1b6d8 (character); stack = object  [asm Confirmed]
  if FUN_005245d0(char,pick) or FUN_00524520(char,pick): Client_SendUseObject_IfInteractable()
  FUN_0093e120(pick)
if DAT_00d1bdfa: return vtbl+0x380(...)
if no select: goto default flag path
if DAT_00d1d900 != -1: FUN_00941ac0; skip UseObject+switch body partially
if obj+0x11c and SQRT(pos-player) <= 25.0f: Client_SendUseObject()  // FCOMIP vs DAT_00aaa6fc
switch cloneType(*(obj+0xa8)+0x38):
  3: break
  4: send 0x205D size 0x10
  0xe/12/14: maybe clear select
  0x16: FUN_00938670
  default: maybe set +0xa32
vehicle flag helper; if param_3 set +0xa32; return 1
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Large multi-path pick manager | **High** | ~300-line body; stages mapped |
| Live decompile ≡ raw | **High** | residual re-check ≡ body |
| Distance gate `DAT_00aaa6fc` = **25.0f** before SendUseObject | **Confirmed** | FSQRT+FCOMIP @ `0x00924ed1` + `read_memory` |
| Post-dist scale `DAT_00aaacbc` = **0.015f** | **Confirmed** | FMUL sites + memory |
| Companion gather scales 10 / 5 / cap40 | **Confirmed** | MULSS + COMISS |
| UseObject when `obj+0x11c != 0` | **High** | Explicit branch pre-dist |
| IfInteractable after `005245d0` \| `00524520` | **Confirmed** | asm order @ `0x00924d8c`…`0x00924db6` |
| Matcher ECX = `DAT_00d1b6d8` | **Confirmed** | both CALL sites |
| Dual-send CF possible (IfInteractable then SendUseObject) | **High** static | wire open |
| GatherTargetsInArea soft pick | **High** | mode **3** then mode **2** (not bitmasks) |
| Type-4 packet opcode `0x205D` | **High** | Imm bits = QuestItemPickup |
| Soft `param_3==0` enables first ray/gather block | **High** | CF + caller `FUN_009251d0` |
| Soft vs commit product naming | **Probable** | Caller only supplies 0/1 |
| Gather mode **PDB English** names | **Tentative** | numeric CF High via `aa_0058d330` |
| Clean ≡ every branch of raw | **High** (CF) | Comments added; no branch invent |
| Full input taxonomy English-sealed | **Partial** | Secondary FUN_* residual |
| Server range authority | **N/A this unit** | Product 30f separate |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Early mode bails | **Yes** |
| Special `DAT_00d1a8da` path | **Yes** |
| Ray / gather / resolve | **Yes** |
| Self/vehicle filter | **Yes** |
| Store + IfInteractable | **Yes** |
| Distance-gated SendUseObject | **Yes** |
| Type switch incl. 0x205D | **Yes** |
| No invented UseObject without flag/distance | **Yes** |
| No merge of −1 vs 0 objective sentinels | **Yes** (deferred to callees) |

---

## 6. UseObject chain fidelity

| Link | Sealed here? |
|---|---|
| This unit → IfInteractable | **Yes** (call site) |
| This unit → SendUseObject | **Yes** (gate High) |
| Send bodies / packet layout | **Callee duals** (not re-opened) |
| Objective matchers | **Callee duals** (`aa_00524520`) |
| Server ObjectUseManager | **Out of scope** |

---

## 7. Gaps / open

1. Product names for `FUN_00490070`, `FUN_004cff70`, `FUN_0075c340`, `FUN_0093e120`, `FUN_0058cd60`.
2. ~~Exact ECX into `FUN_00524520`~~ — **closed**: `DAT_00d1b6d8` (asm).
3. Runtime click capture (soft vs commit, type-4 vs UseObject, dual-wire).
4. Dual-send on one click: **CF sealed possible**; production wire still open.
5. Full meaning of `DAT_00d1a8da` / `DAT_00d1bdfa` modes.
6. Gather mode / helper **PDB English** (numeric modes 3/2 sealed).

**Verdict:** Interact pick + **UseObject 25.0f gate**, **0.015f scale**, **matcher ECX**, and **IfInteractable branch** sealed. Remaining residual is helper English names / runtime wire — not the C2S range contract. **accept-with-gaps.**
