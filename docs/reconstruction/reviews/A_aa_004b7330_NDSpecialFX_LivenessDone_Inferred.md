# Review A (reconstruction fidelity): `aa_004b7330` NDSpecialFX_LivenessDone_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7330` |
| **VA** | `0x004b7330`–`0x004b73bc` (140 B / `0x8C`) |
| **Canonical name** | `NDSpecialFX_LivenessDone_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004b7330` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W26-H) |
| **Counterpart** | `reviews/B_aa_004b7330_NDSpecialFX_LivenessDone_Inferred.md` |
| **System** | client-fx / NDSpecialFX lifecycle |
| **Verdict** | **accept** — leaf CF + ABI + HostTick polarity sealed |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **liveness / completion probe** for an NDSpecialFX host:

- Residual host flags `+9`, `+0xA`, ints `+0x1E4`, `+0x214` must be clear.
- Owned circular list `+0x204`: every payload `node[2]` must have `+0x795 != 0`.
- Optional secondary list `+0x1EC` when `+0x1F0 != 0` and `+6/+7/+8` all 0: any payload with `+0x10B != 0` forces not-done.
- Return **1** = done (HostTick → DeactivateClear); **0** = still live.

Evidence: sole caller dualed `NDSpecialFX_HostTick_Inferred` (W24-C) treats non-zero as done; shared `+0x204` list with HostTick child walk.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004b7330` |
| Bounds | `get_function_by_address` → `004b7330`–`004b73bc` |
| Entry/exit bytes | `read_memory` @ `0x004b7330`, `0x004b73a0` |
| Callers | `FUN_004b8ed0` @ `0x004b8f55` only |
| Peer dual | `NDSpecialFX_HostTick_Inferred` (W24-C) |
| Raw / annotated / clean | W26-H updated |

**Not performed:** Launcher, runtime golden, bit-exact, product English of flag bytes.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `004b7330`–`004b73bc` (140 B) | **Confirmed** | `get_function_by_address` |
| Leaf (0 callees) | **Confirmed** | analyze + decompile |
| ECX this + plain `RET` (`C3`) | **Confirmed** | epilogue samples `5F 5E C3` / `32 C0 C3` |
| Return AL 0 / 1 | **Confirmed** | `B0 01` / `32 C0` paths |
| Host residual gates | **Confirmed** | decomp ≡ raw |
| Owned list `+0x204` / payload `+0x795` | **Confirmed** | decomp + HostTick layout |
| Secondary list polarity | **Confirmed** | decomp while-loop |
| Product method name | **Inferred** | `_Inferred` |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Host residual four-way AND | Yes |
| Owned list walk / early 0 | Yes |
| Default done=1 | Yes |
| Secondary list gate (+1f0, +6/7/8) | Yes |
| Secondary active → done=0 | Yes |
| Early fail plain ret 0 | Yes |
| Success pop esi/edi ret | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `NDSpecialFX_HostTick_Inferred` (`FUN_004b8ed0`) | `0x004b8f55` | non-zero → DeactivateClear + return 1 |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Product English of host flags `+6..+A` and payload `+0x795` / `+0x10B` beyond polarity.
3. Runtime golden vs HostTick deactivate timing.

**Verdict:** **accept** — sealed leaf CF, ABI, and HostTick polarity; product name residual only.
