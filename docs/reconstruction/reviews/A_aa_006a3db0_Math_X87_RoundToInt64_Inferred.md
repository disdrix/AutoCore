# Review A (reconstruction fidelity): `aa_006a3db0` Math_X87_RoundToInt64_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3db0` |
| **VA** | `0x006a3db0` |
| **Canonical name (Ghidra)** | `FUN_006a3db0` |
| **Proposed name** | `Math_X87_RoundToInt64_Inferred` (**High** role; product/CRT twin open) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_006a3db0_Math_X87_RoundToInt64_Inferred.md` |
| **System** | math / x87 float→int helper |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**x87 helper:** convert the value currently in **ST0** to a signed **64-bit integer** via hardware **ROUND** (`FRNDINT` / decompiler `ROUND`), with a **post-round half-case adjustment** using the residual `ST0 - rounded` float bit pattern.

No C stack formals. Callers leave a float in ST0 (often after mul/add of game scalars) and consume the integer return in **EAX:EDX** (`ulonglong` / truncated to short/int at call site).

Distinct from CRT `ftol` scaffold (`reconstructed-exact/ftol.cpp`) — this is a **game-local** hot helper with many in-image callers (LevelUp UI scalar, tac-arc mesh, outpost pulse XP, graphics counts, etc.).

### Control flow (summary)

1. `u = (int64)ROUND(ST0)` — store as lo `local_20` / hi `uStack_1c`.
2. If rounded result is **all-zero** (lo==0 and high magnitude bits clear under mask `0x7fffffff00000000`): **return u** (no half adjust).
3. Else if residual sign test (`(int)fVar3 < 0` path — negative input arm):
   * `u += (0x80000000 < (uint)bitcast(-(float)(ST0 - (float10)u)))` — add 0/1 from half-compare on residual bits.
4. Else (non-negative arm):
   * `adj = (0x80000000 < (uint)bitcast((float)(ST0 - (float10)u)))`
   * `u = CONCAT44(hi - borrow, lo - adj)` — subtract 0/1 with borrow into high dword.

Returns `u` as `ulonglong` (EAX=lo, EDX=hi typical).

**Not** pure truncate (`fistp` alone). **Not** float remainder. **Not** domain logic.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x006a3db0` |
| Entry bytes | `read_memory` @ `0x006a3db0` — `push ebp; mov ebp,esp; sub esp,0x20; and esp,~0xf; fld st0; … fistp/frndint sequence` |
| Callers (sample) | `get_function_callers` — `CVOGCharacter_LevelUp`, `CVOGTacArc_UpdateMesh`, `FUN_00402090`, outpost/gfx/mesh family (50+ listed) |
| Prior notes | LevelUp clean uses return as UI short scalar; outpost pulse XP dual cites round(span×%) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_006a3db0` |
| Function record | `docs/reconstruction/functions/aa_006a3db0_FUN_006a3db0.md` |

**This pass:** live decompile; callers; entry bytes. **Not performed:** exhaustive half-case golden table, Launcher, ledgers.

---

## 3. Signature

```c
// Implicit: input float in x87 ST0. No stack args.
// Return: int64 in EDX:EAX (decompiler ulonglong).
int64_t Math_X87_RoundToInt64_Inferred(void /* ST0 */);
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| (x87 only) | `ROUND` / `FRNDINT` + FPU residual ops — no FUN_* |

| Caller class | Role |
|---|---|
| `CVOGCharacter_LevelUp` | Round UI/race scalar to short |
| `CVOGTacArc_UpdateMesh` | Round mesh angle/count temps |
| `Outpost_ComputePulseXp` family | Round XP float product |
| Broad gfx/UI/phys sites | Generic float→int leaf |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| ROUND(ST0) → int64 | Yes |
| Zero-result early return | Yes |
| Negative vs non-neg residual adjust | Yes |
| `0x80000000` bit-pattern half test | Yes |
| Return ulonglong / int64 | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = ST0 → int64 round helper | **High** | body + universal call pattern |
| No stack formals; FPU in | **High** | decomp `in_ST0` |
| Post-round residual 0/1 adjust | **High** CF | exact product rounding mode open |
| Identical to MSVC CRT `__ftol2` | **Tentative** | similar shape; not byte-proven twin |
| Half-away vs banker's vs chop+correct | **Probable** round family | need golden vectors |
| Product symbol | **Open** | structural `_Inferred` |

---

## 7. Gaps / open

1. Exact IEEE half-case policy (golden table not run this pass).
2. Whether any caller relies on high dword (most truncate to 32/16).
3. Relationship to CRT `ftol` / `__ftol2` image copies.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — role/CF High; rounding-mode product name open.
