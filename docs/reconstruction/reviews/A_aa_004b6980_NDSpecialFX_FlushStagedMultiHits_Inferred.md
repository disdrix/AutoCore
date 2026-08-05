# Review A (reconstruction fidelity): `aa_004b6980` NDSpecialFX_FlushStagedMultiHits_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6980` |
| **VA** | `0x004b6980` |
| **Canonical name (Ghidra)** | `FUN_004b6980` |
| **Proposed name** | `NDSpecialFX_FlushStagedMultiHits_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | (consumer of stage `004b67d0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004b6980_NDSpecialFX_FlushStagedMultiHits_Inferred.md` |
| **System** | `combat` / SpecialFX → multi-target apply |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Flush staged SpecialFX multi-target entry buffer into `Client_Combat_ApplyMultiTargetHits_Inferred`, then free the buffer.**

Sole consumer of stage producer `NDSpecialFX_StageTargetEntries_Inferred` (`0x004b67d0`) fields:

| Offset | Role |
|---|---|
| `fx+0x3C` | staged entry array pointer (null = no-op) |
| `fx+0x40` | entry count |
| `fx+0x48` | TFID of attacker/source object |

### Control flow

1. If `this+0x3C == 0` → return.
2. `src = Object_ResolveFromTFID(this+0x48)`.
3. `FUN_004da2e0(entries@+0x3C, count@+0x40, src, 1, 1, 0, DAT_009cb2a0..ac, 0)`.
   * Masks at `DAT_009cb2a0` read as `0xFFFFFFFF / 0xFFFFFFFF / 0 / 0` (identity mask for floater gate — **High** from live `read_memory`).
4. `operator_delete(+0x3C)` (Ghidra noreturn artifact); clear `+0x3C = 0`.

**Not** staging (`004b67d0`), not single-hit apply (`004d78e0`/`004d7e30`), not deferred enqueue alone.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004b6980` |
| Callers | `get_function_callers` → `004b0f80`, `004b7150`, `00595230` |
| Parent dual | `A_aa_004da2e0_*` (consumer); stage `A_aa_004b67d0_*` |
| Constants | `read_memory` `DAT_009cb2a0` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004b6980` |
| Function record | `docs/reconstruction/functions/aa_004b6980_FUN_004b6980.md` |

**This pass:** live decompile; callers; parent dual; constant read. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall/fastcall — ECX = SpecialFX session/object
void __fastcall NDSpecialFX_FlushStagedMultiHits_Inferred(void *fx);
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `Object_ResolveFromTFID` | Source object from `fx+0x48` |
| `FUN_004da2e0` | Multi-target hit apply |
| `operator_delete` | Free staged array |

| Caller | Role |
|---|---|
| `0x004b0f80` / `0x004b7150` / `0x00595230` | FX lifecycle flush points |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null `+0x3C` early out | Yes |
| Resolve TFID + multi-hit call | Yes |
| Free + zero pointer | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Flush staged entries → multi-hit | **High** | only body |
| Layout +0x3C/+0x40/+0x48 | **High** | matches stage dual |
| Identity mask constants | **High** | memory 0xFFFFFFFF pairs |
| Product name | **Tentative** | `_Inferred` |
| Decompiler thiscall lost | **Probable** | `__fastcall` in raw |

---

## 7. Gaps / open

1. Retail SpecialFX class name for host.
2. Exact call-site timing in FX lifecycle.
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — flush CF High.
