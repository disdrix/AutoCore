# Review A (reconstruction fidelity): `aa_00531570` CVOGCharacter_TryType1aSimpleExchange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531570` |
| **VA** | `0x00531570` |
| **Canonical name** | `CVOGCharacter_TryType1aSimpleExchange_Inferred` |
| **Review date** | `2026-08-04` (WQ-008 residual WQ8R-B) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_00531570_CVOGCharacter_TryType1aSimpleExchange_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Single-ingredient type-`0x1a` exchange** on the local character:

1. Require cargo + locker grids.
2. Gate `object+0x38 == 0x1a` and non-null def blob `+0x3c`.
3. Dual-count ingredient CBID `blob+0x4c0` on cargo then locker (`includeBroken=0`).
4. If `requestQty <= have`: compute `outCount = u8(blob+0x4c9) * requestQty`, `outCbid = object+0x34`.
5. `FindFreeSlot` on **cargo** with InvSize `blob+0x406/+0x407`, page **`-1`**.
6. `RemoveInventoryItem` cargo then locker remainder; `FUN_005310a0(ctx, outCbid, outCount)`.
7. Return **1** / **0**.

**Does not** place/stamp cells (FindFree is probe-only; grant goes through give helper + AddItem path).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00531570_FUN_00531570.md` |
| Annotated | `docs/reconstruction/raw/aa_00531570_FUN_00531570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryType1aSimpleExchange_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00531570_CVOGCharacter_TryType1aSimpleExchange_Inferred.md` |
| Live decompile | Ghidra MCP `batch_decompile` @ `0x00531570` (2026-08-04) — ≡ raw |
| Bytes | Ghidra MCP `read_memory` @ entry + body (ECX seals) |
| Callee duals | `aa_005711c0` CountItemsByCbid; `aa_005713a0` FindFreeSlot; `aa_005721c0` RemoveInventoryItem |
| FindFree caller table | residual `a_005713a0` / A_aa_005713a0 (this VA, page `-1`) |

**Not performed:** `disassemble_bytes`, Launcher, live CE, parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall`, `ret 8`, two stack args | **High** | epilogue `c2 08 00` |
| `this` = character (`+0x250`, `+0xcbc`) | **High** | body + inventory map |
| Type gate `+0x38 == 0x1a` | **High** | `83 7a 38 1a` |
| Dual count cargo then locker | **High** | `mov ecx,ebx` / `mov ecx,ebp` before Count |
| Ingredient `blob+0x4c0`, mult `+0x4c9` | **High** | loads + imul |
| Product CBID `object+0x34` | **High** | pushed to give helper |
| FindFree on **cargo**, page `-1` | **High** | `mov ecx,ebx`; `push -1` |
| Remove cargo then locker remainder | **High** | ECX sequence + sub qty |
| Give via `FUN_005310a0` (cbid, qty) | **High** | call site + callee `ret 8` |
| Clean ≡ raw CF (with ECX restored) | **High** | annotated + clean |
| Product English for type 0x1a | **Tentative** | no string here → `_Inferred` |
| Caller set | **Open** | zero direct xrefs |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null object / missing cargo or locker → 0 | **Yes** |
| Type `0x1a` + blob null → 0 | **Yes** |
| Dual Count sum vs qty | **Yes** (ECX from bytes) |
| Mult × qty; outCbid == -1 / outCount ≤ 0 → 0 | **Yes** |
| FindFree fail → 0 | **Yes** |
| Remove dual-grid + Give + return 1 | **Yes** |

---

## 5. Gaps

1. Original / RTTI name for type **`0x1a`** and this method.
2. Dispatch callers (vtable / reaction) — no static CALL xrefs.
3. Whether give helper `this` is bare character vs MI reaction ctx on all paths (call pushes character from this unit).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps** — inventory CF + dual-grid ECX **sealed**.
