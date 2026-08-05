# Review B (skeptical / adversarial): `aa_005e1030` LootCatalog_RollCandidateId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1030` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005e1030_LootCatalog_RollCandidateId_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `005e1150` | `1150` filters via exclusion list + `005e0cd0`; this uses `005e07d0` only | **Falsified** merge |
| 2 | Always returns valid ID | Empty/null vector → `0xffffffff` | **Survives** as fail path |
| 3 | `operator_delete` truly noreturns / process exit | SEH frame; known decompiler artifact | **Survives** as noise |
| 4 | Mode values beyond 0/1 still roll | Explicit `return 0xffffffff` for mode ∉ {0,1} | **Survives** |
| 5 | Is pure getter of global | Calls `005e07d0` + RNG pick | **Falsified** as getter |
| 6 | Product name sealed | No plate string | **Survives** `_Inferred` gap |

---

## 2. Live ≡ raw

Live decompile matches raw `aa_005e1030`: SEH `LAB_009a7478`, mode branch on `in_stack_00000024`, 8-dword copy, `FUN_005e07d0`, null/`>>2` checks, RNG + `007a41f0`, dual `operator_delete` paths.

---

## 3. Surviving contract

```
// this = loot catalog
// mode = stack formal:
//   0 → table @ this+0x8700c
//   1 → table @ this+0xc
//   else → return -1
// pack 8 stack dwords → FUN_005e07d0 → candidate vector
// if empty/null → -1
// else random-pick one ID; free vector; return ID
```

**Gaps kept:** 8-dword schema; exact pick helper ABI; retail names of table roots.

**Verdict:** **accept-with-gaps**.
