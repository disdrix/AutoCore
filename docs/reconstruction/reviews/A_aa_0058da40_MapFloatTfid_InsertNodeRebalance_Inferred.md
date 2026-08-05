# Review A (reconstruction fidelity): `aa_0058da40` MapFloatTfid_InsertNodeRebalance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058da40` |
| **VA** | `0x0058da40` |
| **Canonical name** | `MapFloatTfid_InsertNodeRebalance_Inferred` (was `FUN_0058da40`) |
| **Ghidra symbol** | `FUN_0058da40` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0058da40_MapFloatTfid_InsertNodeRebalance_Inferred.md` |
| **System** | skills-abilities / std map helper (float-key TFID tree) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** — MSVC red-black insert shape sealed; product map type open |

---

## 1. Purpose

MSVC-style **tree insert + rebalance** helper used by `MapFloatTfid_InsertByKey` (`FUN_0058def0`):

1. If `tree+8` (size) `> 0x0aaaaaa8` → throw `"map/set<T> too long"`.
2. `FUN_005a2de0` allocates/constructs node from parent + payload key.
3. Size++; link as left/right/root per `param_3` side hint and parent.
4. Red-black fixup loop on color byte at **node+0x28** (and parent); rotates via `FUN_004192a0` / `FUN_004192f0`.
5. Root color black; `*outIterator = newNode`.

Sole static caller: `FUN_0058def0` (gather distance-sort insert).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0058da40` |
| Raw | `raw/aa_0058da40_FUN_0058da40.md` |
| Parent dual | `A_aa_0058def0_MapFloatTfid_InsertByKey_Inferred.md` |
| Xrefs | sole `FUN_0058def0` |

---

## 3. Signature

```c
void __thiscall InsertNodeRebalance(
  Tree* tree,            /* +4 head, +8 size */
  Node** outIt,          /* param_2 */
  char insertLeft,       /* param_3 */
  Node* parent,          /* param_4 */
  /* key/payload */ param_5);
```

Color field: **`+0x28`** on node (matches erase dual family).

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| map/set too long throw | **High** |
| Size++ + parent link | **High** |
| RB rebalance via 004192a0/f0 | **High** shape |
| Sole insert-by-key caller | **High** |
| Exact node payload layout (TFID@?) | **Medium** (in 005a2de0 / parent framing) |

**Verdict:** **accept-with-gaps**
