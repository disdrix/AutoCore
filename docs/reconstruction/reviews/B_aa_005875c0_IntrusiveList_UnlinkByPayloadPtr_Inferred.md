# Review B (skeptical / adversarial): `aa_005875c0` IntrusiveList_UnlinkByPayloadPtr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005875c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005875c0_IntrusiveList_UnlinkByPayloadPtr_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Frees the matched payload object | Only `operator_delete(node)` | **Falsified** as payload free |
| 2 | STL map erase | Linear DLL walk; no isnil/`004baa30` | **Falsified** as map |
| 3 | Clears entire list | Single match then stop | **Falsified** as full clear |
| 4 | FX-only helper | Callers include mission staging + CompleteObjective | **Falsified** as FX-only |
| 5 | Compares node pointer to key | Compares `node[2]` payload to `*key` | **Survives** payload match |
| 6 | Nested loop is multi-match remove | After match unlinks once; delete ends | **Survives** as first-only |

---

## 2. Live ≡ raw

Live decompile matches raw `aa_005875c0` (short body). Usage in `ClearMissionStagingTree` dual (`this = char+0xCC4`) and TeardownCore bit0 path confirms generic list helper.

---

## 3. Surviving contract

```
// thiscall list{ head*@+4 }
// for node in circular list:
//   if node->payload == *key:
//     unlink node; operator_delete(node); return
// return  // not found
```

**Gaps kept:** payload ownership; multi-match policy; per-caller list type.

**Verdict:** **accept-with-gaps**.
