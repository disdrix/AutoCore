# Review A (reconstruction fidelity): `aa_005316c0` CVOGCharacter_TryType1aCraft_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005316c0` |
| **VA** | `0x005316c0` |
| **Canonical name** | `CVOGCharacter_TryType1aCraft_Inferred` |
| **Review date** | `2026-08-04` (WQ-008 residual WQ8R-B) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_005316c0_CVOGCharacter_TryType1aCraft_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Mode-aware multi-ingredient craft** for type-`0x1a` recipe objects:

1. Require cargo + locker; `craftQty > 0`.
2. Ensure def blob (`FUN_004f1e20` if `object+0x3c == 0`).
3. `FUN_00522060(character, obj, &available, mode, 0)` — if not craftable → **return 1** (soft no-op).
4. If `craftQty > available` → **0**.
5. `FindFreeSlot` on **cargo**, InvSize `blob+0x406/407`, page **`-1`**.
6. **Primary bank** (if `mode != 1` and `blob+0x4d4 > 0`): CBID `+0x4d0`, cost `+0x4d4` per batch; dual-grid count/remove; may split batches with secondary.
7. **Secondary list** (if `mode != 2`): up to 5 CBIDs at `+0x498` (`FUN_00599dd0` slot count); remove `secondaryNeed` of each non-`-1`.
8. Give `*(blob+4)` × `totalOut` via `FUN_005310a0`.
9. Return **1**.

Sibling **simple** exchange: `aa_00531570` (single `+0x4c0` / mult `+0x4c9` / product `object+0x34`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005316c0_FUN_005316c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005316c0_FUN_005316c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryType1aCraft_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_005316c0_CVOGCharacter_TryType1aCraft_Inferred.md` |
| Live decompile | Ghidra MCP `batch_decompile` @ `0x005316c0` — ≡ raw |
| Bytes | `read_memory` entry + craft body (ECX, mode, ret 12) |
| Helper decompiles | `FUN_00522060`, `FUN_00599dd0`, `FUN_004f1e20`, `FUN_005310a0` |
| Callee duals | Count / FindFree / Remove (inventory-transfer) |

**Not performed:** `disassemble_bytes`, Launcher, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall`, `ret 12`, three stack args | **High** | `c2 0c 00` |
| Soft success when craftable-count fails | **High** | raw: `if (cVar3==0) return 1` |
| Hard fail when `qty > available` | **High** | raw compare |
| FindFree cargo + page `-1` | **High** | bytes `mov ecx,esi` cargo; `push -1` |
| Mode 1 skips primary; mode 2 skips secondary | **High** | `cmp` / `setne` vs 1 and 2 |
| Primary cost `char+0x4d4`, CBID `+0x4d0` | **High** | loads + imul/div |
| Secondary 5× dword list `+0x498` | **High** | `FUN_00599dd0` + loop stride 4 |
| Product CBID `blob+4` | **High** | give call first stack |
| Dual-grid remove pattern | **High** | same family as simple twin |
| Type `0x1a` enforced inside this body | **Probable** | enforced in `FUN_00522060` (`object+0x38==0x1a`); this unit does not re-cmp 0x1a |
| Clean ≡ raw CF | **High** | with ECX restored |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null / missing cargo / qty≤0 / missing locker → 0 | **Yes** |
| Blob ensure + null → 0 | **Yes** |
| Count helper false → return 1 | **Yes** |
| qty > available → 0 | **Yes** |
| FindFree fail → 0 | **Yes** |
| Primary optional + secondary optional + give → 1 | **Yes** |

---

## 5. Gaps

1. Product English for type `0x1a` / craft UI name.
2. Callers (no direct xrefs).
3. Full dual of `FUN_00522060` / `FUN_00599dd0` / `FUN_005310a0` (callees only here).
4. Whether soft-success `return 1` is intentional product design or mission-script quirk.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps.**
