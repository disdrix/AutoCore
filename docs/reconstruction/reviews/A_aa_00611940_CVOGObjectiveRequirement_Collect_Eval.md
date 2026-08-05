# Review A (reconstruction fidelity): `aa_00611940` Collect_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611940` |
| **VA** | `0x00611940` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_Eval` |
| **Review date** | `2026-07-29` (dual residual strengthen; CountItems bridge) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00611940_CVOGObjectiveRequirement_Collect_Eval.md` |
| **Verdict** | **accept** (body + CountItems bridge sealed; runtime/diff open) |
| **Scratch** | `reviews/a_00611940.md` |

---

## 1. Purpose

Collect requirement **Eval** (vtable **+0x10** on Collect `PTR_FUN_009e12c4`). Returns progress fraction in `[0,1]` from **live cargo inventory**:

```
min(1.0, CountItemsByCbid(cargo, CBID, includeBroken=0) / NumToCollect)
```

Does **not** read objective-state slot floats (contrast UseItem/Kill Eval).

---

## 2. Inspected artifacts

| Artifact | Path / note |
|---|---|
| Live Ghidra | `decompile_function` @ `0x00611940` (re-verify this pass) |
| Live Ghidra | `read_memory` body `0x00611940`–`0x006119cf` (160 B) |
| Live Ghidra | `read_memory` vtable `0x009e12c4` (48 B); constants `0x00a0f2a0`, `0x00a0f518` |
| Live Ghidra | `get_xrefs_to` → sole **DATA** `0x009e12d4`; `get_function_callers` empty |
| Count bridge | decompile `0x005711c0` + dual residual `a_005711c0.md` |
| Sibling | SlotAction `0x006124b0` (same cargo + double-Count pattern) |
| XML | deserialize `0x00611a00` (`CBID`→+0x10, `NumToCollect`→+0x14) |
| Family ABI | UseItem_Eval `0x0060cfe0` (`RET 8`, stack1=state) |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Collect_Eval.cpp` |
| Function record | `functions/aa_00611940_CVOGObjectiveRequirement_Collect_Eval.md` |
| Chain | `reviews/CHAIN_2026-07-29_inventory_collect.md` |
| Residual | `reviews/a_00611940.md` |

**Not used:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff.

---

## 3. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| NumToCollect @ req+0x14; zero → return 1.0 | **High / Confirmed** | `CMP [ESI+0x14],0`; early `FLD g_flOne; RET 8` |
| Item CBID @ req+0x10 | **High / Confirmed** | both Count sites `PUSH [ESI+0x10]`; XML `CBID` |
| Character = stack0 (after PUSH ESI/EDI → `[ESP+0xC]`) | **High / Confirmed** | `MOV EDI,[ESP+0xC]` |
| stack1 unread (family formal) | **High / Confirmed** | no load; UseItem loads stack1 only |
| ABI `RET 8` (three exits) | **High / Confirmed** | bytes `C2 08 00` @ complete-zero, success, zero paths |
| Cargo path `char+0x250 → +0x2b0` | **High / Confirmed** | `MOV EAX,[EDI+0x250]`; `MOV ECX,[EAX+0x2b0]` (×1–2) |
| Missing vehicle or grid → 0.0 | **High / Confirmed** | null tests → `FLD g_flZero` |
| Count callee `0x005711c0` | **High / Confirmed** | rel32 from `0x00611972` and `0x006119a3` both resolve to `0x005711c0` |
| Count `this` = cargo grid (ECX thiscall) | **High / Confirmed** | ECX set to grid before each CALL; decomp flattens arg |
| includeBroken = 0 both sites | **High / Confirmed** | `PUSH 0` before both CALLs |
| Broken stacks excluded from progress | **High** | Count residual bit19; includeBroken=0 |
| Complete when ratio ≥ 1.0 → return 1.0 | **High / Confirmed** | `COMISS XMM0,XMM1` (1.0 vs ratio); `JBE` skips re-count; XMM0 stays 1.0 |
| Incomplete → second Count then ratio return | **High / Confirmed** | fall-through reloads cargo ECX; CALL @ `0x006119a3` |
| SSE ratio + x87 `FLD` return (`float10` decomp) | **High / Confirmed** | `CVTSI2SS`/`DIVSS`/`MOVSS`; `FLD [ESP+0xC]` |
| g_flOne @ `0x00a0f2a0` = 1.0f | **High / Confirmed** | `read_memory` `00 00 80 3f` |
| g_flZero @ `0x00a0f518` = 0.0f | **High / Confirmed** | `read_memory` `00 00 00 00` |
| Vtable Collect +0x10 only DATA xref | **High / Confirmed** | `0x009e12d4` = LE `40 19 61 00` |
| Collect type=2 / XML fields | **High** | ctor + `0x00611a00` |
| Clean ≡ body CF (behavioral) | **High** | double-count + clamp model |
| Name Collect_Eval | **High** (layout/RTTI/vtable); original PDB open | |

---

## 4. Control flow: clean ≡ decomp ≡ body bytes

| Stage | Match |
|---|---|
| NumToCollect==0 → 1.0 | **Yes** |
| Null cargo path → 0.0 | **Yes** |
| Count(cbid, 0) on cargo | **Yes** (×1 always if cargo; ×2 if incomplete) |
| Clamp complete to 1.0 | **Yes** (`COMISS` + keep XMM0=1.0) |
| Incomplete return count/Num | **Yes** |
| `RET 8` | **Yes** |

### Byte-level Count bridge (this pass)

| Site | VA | Encoding | Target |
|------|-----|----------|--------|
| First CALL | `0x00611972` | `E8 49 F8 F5 FF` | `0x005711c0` |
| Second CALL | `0x006119a3` | `E8 18 F8 F5 FF` | `0x005711c0` |

Both: ECX = cargo grid; stack args = CBID, then `0` (includeBroken).

### COMISS polarity

```
XMM0 = 1.0; XMM1 = count/Num
COMISS XMM0, XMM1   ; flags from 1.0 − ratio
JBE skip_recount    ; 1.0 ≤ ratio → complete (no 2nd Count)
```

Equality at exact NumToCollect **completes** (not strict `>`).

---

## 5. CountItems bridge (owned cross-link)

| Side | Contract |
|------|----------|
| **Callee** | `InventoryGrid_CountItemsByCbid` `aa_005711c0` |
| **this** | cargo `InventoryGrid*` at `*( *(char+0x250) + 0x2b0 )` |
| **itemCbid** | `*(req+0x10)` |
| **includeBroken** | always `0` → Broken bit19 stacks **do not** advance Eval |
| **Sibling consumer** | SlotAction `0x006124b0` same cargo + same Count; also double-calls when count &lt; need (compiler pattern, not CSE artifact) |

This is the sealed **inventory ↔ Collect progress** bridge for Eval. Server absolute progress remains S2C `0x2071` (separate authority).

---

## 6. Gaps closed this residual strengthen

1. ~~Double Count decompiler artifact?~~ → **real** two CALL sites; 2nd iff ratio &lt; 1; SlotAction isomorphic.
2. ~~Count ECX / includeBroken framing~~ → **byte-sealed**.
3. ~~COMISS complete polarity / equality~~ → **≥** completes (`JBE`).
4. ~~Constant addresses~~ → **re-read** 1.0f / 0.0f.
5. ~~Vtable slot for Eval~~ → `+0x10` at DATA `0x009e12d4` (not +0x8 like Kill).

---

## 7. Remaining gaps (policy / out-of-unit)

1. Runtime journal refresh / GrabResponse → Eval timing.
2. Bit-exact / image binary diff.
3. Original PDB symbol.
4. Virtual dispatch callers (no static CODE xrefs — expected).

**Verdict:** **accept** — dual residual sealed for Collect_Eval body + CountItems bridge. Runtime/diff remain open policy.
