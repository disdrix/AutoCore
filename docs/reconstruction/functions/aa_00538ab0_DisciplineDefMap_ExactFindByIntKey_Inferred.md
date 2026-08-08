# Function record (named): DisciplineDefMap_ExactFindByIntKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538ab0` |
| **Inferred name** | `DisciplineDefMap_ExactFindByIntKey_Inferred` |
| **Ghidra name** | `FUN_00538ab0` |
| **VA** | `0x00538ab0`–`0x00538b17` |
| **System** | `skills-abilities` |
| **Dual** | R13-037 A/B accept-with-gaps (2026-08-05, dual start 2686) |
| **Terminal** | **false** |
| **Parent** | `0x0052b040` DisciplineDefMap_TryCopyPayloadById_Inferred |

See sibling record `aa_00538ab0_FUN_00538ab0.md` for full seals, callers, and artifacts.

```c
void *__thiscall DisciplineDefMap_ExactFindByIntKey_Inferred(
    void *mapHeader /* ECX, image: 0x00b045b0 */,
    void **pOutNode,
    const int *pKey);
// ret 8; *pOutNode = node* or end (DAT_00b045b4); nil @ +0x20d; key @ +0x0C
```

**Port note:** exact find only (not open lower_bound). After call, treat `node == *(map+4)` / `DAT_00b045b4` as miss. Payload at `node+0x10` is **0x1FC** for DisciplineDef consumers — this unit does not copy. Do **not** merge with SkillDefMap find (`0x00418890`, nil `+0x641`) or nearby `0x00538a40` (nil `+0x49`).
