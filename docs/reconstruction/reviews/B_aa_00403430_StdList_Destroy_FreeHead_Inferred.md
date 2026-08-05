# Review B (skeptical / adversarial): `aa_00403430` StdList_Destroy_FreeHead_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403430` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00403430_StdList_Destroy_FreeHead_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `operator_delete` never returns | Ghidra WARNING only; free returns | **Falsified** as CF |
| 2 | Frees entire list alone | Only free after clear; clear owns node walk | **Survives** as two-step dtor |
| 3 | Is custom game list w/ CS | No CS/vtbl; plain head/size | **Falsified** vs `List_ClearDestroy` `0040dc40` |
| 4 | Domain-specific (mission-only) | 50+ xrefs across map/UI/combat | **Falsified** — shared util |
| 5 | Returns value | No EAX contract used by callers after call | **Survives** void |

---

## 2. Live ≡ raw

```
// force_decompile 0x00403430
FUN_00404060();
operator_delete(*(void **)(param_1 + 4));
```

Matches raw/clean. Dependency: clear dual seals `+4`/`+8`.

---

## 3. Surviving contract

```
// ECX=list*
// clear nodes+size; free sentinel at +4
```

**Gaps kept:** multi-node free quality lives in `00404060`.

**Verdict:** **accept-with-gaps**.
