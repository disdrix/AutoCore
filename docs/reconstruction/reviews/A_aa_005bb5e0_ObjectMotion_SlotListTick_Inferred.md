# Review A (reconstruction fidelity): `aa_005bb5e0` ObjectMotion_SlotListTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bb5e0` |
| **VA** | `0x005bb5e0`–`0x005bb666` (134 B / `0x86`) |
| **Canonical name** | `ObjectMotion_SlotListTick_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_005bb5e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W27-D) |
| **Counterpart** | `reviews/B_aa_005bb5e0_ObjectMotion_SlotListTick_Inferred.md` |
| **System** | client object motion / reaction slot list |
| **Verdict** | **accept** — CF + ABI + SlotTick linkage + count-- sealed |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Walk motion host circular list `+0xA24`:

- Mirror dt into `DAT_00af3f68`.
- Per node: `ObjectMotion_SlotTick` on `node[2]` with `(flag, dt)`.
- Return **0** → `FUN_005be2b0` + unlink + `operator_delete` + **`+0xA28--`**.
- Return remaining count at `+0xA28`.

Evidence: sole dualed outer caller of SlotTick (W26-H); HostTick site `0x004b9103` after `FUN_005bc3c0` keep.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x005bb5e0` |
| Bounds | `get_function_by_address` → `005bb5e0`–`005bb666` |
| Entry/loop/exit bytes | `read_memory` @ `0x005bb5e0`, `0x005bb600` |
| Global | `DAT_00af3f68` default `3DCCCCCD` ≈ 0.1 |
| Caller | HostTick @ `0x004b9103` (bytes: `8B CD E8 …` ECX=payload) |
| Peer dual | `ObjectMotion_SlotTick_Inferred` (W26-H) |
| Raw / annotated / clean | W27-D updated |

**Not performed:** Launcher, runtime golden, dual of `FUN_005be2b0`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range 134 B | **Confirmed** | bounds + `CC` pad |
| `__thiscall` + **`ret 8`** | **Confirmed** | exit `C2 08 00` |
| SlotTick sole outer caller | **Confirmed** | xrefs + W26-H |
| Count-- on remove | **Confirmed** | `83 87 28 0A 00 00 FF` (decomp gap) |
| `operator_delete` returns | **Confirmed** | loop continues after add esp,4 |
| DAT_00af3f68 dt mirror | **Confirmed** | `movss` + image float |
| Product method name | **Inferred** | `_Inferred` |
| Runtime | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| movss dt → global | Yes |
| Empty list → return count | Yes |
| SlotTick call | Yes |
| Keep → next | Yes |
| Remove → teardown + unlink + delete + count-- | Yes (bytes for --) |
| ret 8 / EAX count | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `NDSpecialFX_HostTick_Inferred` | `0x004b9103` | ECX = `+0x1E0` payload; after `005bc3c0` keep |

---

## 6. Gaps

1. Retail / PDB symbol.
2. `FUN_005be2b0` full dual.
3. Runtime golden multi-remove count.

**Verdict:** **accept** — sealed list-tick CF/ABI/SlotTick/count contract; product name residual only.
