# Annotated low-level: CVOGReaction_ResolveSkillTargets (`aa_0054c570`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054c570` |
| **VA** | `0x0054c570` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_0054c570_CVOGReaction_ResolveSkillTargets.md` (capture 2026-07-23) |
| **Asm re-verify** | 2026-07-29 Ghidra `disassemble_function` |
| **Note** | Despite the name, the body is a **skill runtime materialize** path, not spatial target gathering (that is `Skill_GatherTargetsInArea` / `Skill_ResolveTargetList`). |

---

## 1. Corrected signature (asm-sealed)

```c
// __cdecl — caller ADD ESP,8
SkillRuntime* __cdecl CVOGReaction_ResolveSkillTargets(
    int skillId,        // stack arg0 — map key
    int rankPacked);    // stack arg1 — word stored at runtime+0x5f6
// returns new runtime ptr (0x630-byte object), or NULL on map miss
```

**`unaff_DI` rank: FALSIFIED.** SetRank (`0x005535a0`) is `__thiscall` + one stack arg (`RET 4`). EDI is only the `REP MOVSD` destination register.

---

## 2. Algorithm (body-accurate + asm)

```text
// SEH frame: local_4 / puStack_8 / ExceptionList

if DAT_00b04724 == 0:
    FUN_0054b2c0()                         // skill table load/init

// map this hardcoded ECX = DAT_00b04734
it = FUN_00418890(&out, &skillId)
node = *it

if node == DAT_00b04738:                   // end/head sentinel → MISS
    return NULL

raw = operator_new(0x630)
if raw:
    runtime = FUN_0054f3c0(ECX=raw)        // ctor zeros fields incl +0x5f0
else:
    runtime = NULL                         // still may crash on copy — retail path

// REP MOVSD: 0x18C dwords = 0x630 bytes from (node + 0x10) → runtime
ESI = node + 0x10
EDI = runtime
ECX = 0x18C
REP MOVSD

// Skill_SetRankAndReevaluate: ECX=runtime; push rankPacked; RET 4
// stores word rank at runtime+0x5f6; calls Skill_ReevaluateForCurrentRank
return runtime
```

Copy size check:

```text
0x18C dwords × 4 = 0x630 bytes  → matches allocation size  (Confirmed arithmetic)
```

Source starts at **node+0x10**, so the first 16 bytes of the map node are **not** copied (tree links + key at +0x0c per lower_bound walker).

---

## 3. Globals

| Symbol | Role | Confidence |
|---|---|---|
| `DAT_00b04724` | init-once flag (byte) | **High** |
| `DAT_00b04734` | skill def **map object** (this for find) | **High** (asm `MOV ECX,0xb04734`) |
| `DAT_00b04738` | map end/head **sentinel node pointer** | **High** — miss, not cache |
| `FUN_0054b2c0` | initializes skill definition structures | **High CF** / name Tentative |
| `FUN_00418890` | map find/lower_bound by int key | **High CF** |
| `FUN_0054f3c0` | construct runtime in `0x630` storage | **High CF** |
| `Skill_SetRankAndReevaluate` (`0x005535a0`) | `+0x5f6` rank + reevaluate | **High** |

---

## 4. Side-effect order

1. Optional global skill-table init  
2. Map lookup (read-only on miss)  
3. Heap alloc + ctor + bulk copy + rank write + reevaluate  
4. Return ownership to **caller** (insert tree vs `operator_delete` — caller policy)

---

## 5. Confidence summary

| Dimension | Level |
|---|---|
| CF / sizes / ABI | **High** |
| Null = miss | **High** |
| Rank path | **High** (stack arg1 only) |
| Symbol name | Misnomer (materialize) |
