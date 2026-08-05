# Dual A/B report — `aa_00404d70` GameData_LookupCloneBaseByCbid

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00404d70`. Dual A/B + artifacts. Seal CBID→clonebase tail-thunk ABI.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callees / callers / call-site bytes). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00404d70` GameData_LookupCloneBaseByCbid | **accept** — 10 B tail thunk + `+0xf10` hash + return void* sealed |

---

## Sealed facts

1. **Body:** `0x00404d70`–`0x00404d7a` only. Bytes  
   `8B 89 10 0F 00 00 E9 A5 BB 1A 00` → `MOV ECX,[ECX+0xF10]; JMP 0x005b0920`.

2. **ABI:** `__thiscall` — ECX = game-data host, stack **`uint32_t cbid`**, **`RET 4`** via Lookup, return **`void*`** in EAX (def or NULL).

3. **Not void:** decompiler return type wrong; callers use EAX (GiveItemByCbid null-check + type `def+0x38`, CreateCreature type `0x12`, Collect UI, …).

4. **Sole callee:** `CNDHash_LookupByKey` (`aa_005b0920`) by **tail JMP** (not CALL).

5. **Host field:** `this+0xf10` = **`CNDHash*`** CBID table.

6. **Call-site host:** sampled sites load **`DAT_00b041fc`** into ECX before CALL (not character this). Global is call-site policy, not body constant.

7. **Role:** clonebase / item-definition lookup by CBID — not item construction (factory is `CVOGReaction_GiveItemByCbid`).

8. **Three-rep:** raw CF + live decompile + body bytes; JMP target math confirmed.

9. **Name:** `GameData_LookupCloneBaseByCbid` (role-inferred; host class English open).

10. **Call surface:** 30+ listed function callers across inventory/spawn/mission/vehicle paths.

---

## Gaps

1. Product class name for `DAT_00b041fc` / host.  
2. Full clonebase def layout (caller-owned).  
3. Whether hash is exclusive to items vs all clonebase kinds.  
4. Runtime live verification / bit-exact image diff.  
5. Exhaustive non-function xref catalog (parent residual).

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00404d70_GameData_LookupCloneBaseByCbid.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00404d70_GameData_LookupCloneBaseByCbid.md` | **accept** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00404d70_GameData_LookupCloneBaseByCbid.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00404d70_GameData_LookupCloneBaseByCbid.md` |
| Function record | `docs/reconstruction/functions/aa_00404d70_GameData_LookupCloneBaseByCbid.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GameData_LookupCloneBaseByCbid.cpp` |
| Raw (authoritative body + v2026-07-29 append) | `docs/reconstruction/raw/aa_00404d70_FUN_00404d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00404d70_FUN_00404d70.annotated.md` |
| This report | `docs/agents/task-dual-ab-00404d70-gamedata-lookupclonebasebycbid-report.md` |

Sibling context (not owned): `CNDHash_LookupByKey` `0x005b0920`, host global `DAT_00b041fc`, factory `CVOGReaction_GiveItemByCbid` `0x0051a170`.

---

## AutoCore impact

- Server/data ports: CBID→def is a dictionary lookup (`TryGetValue`); null miss matches retail.
- Do not implement construction inside this unit — only resolve definition pointer.
- Client memory tooling: host at `DAT_00b041fc`, table pointer at `+0xf10`, then standard CNDHash walk (sealed Lookup).
- Ports must return the looked-up pointer; discarding EAX breaks all consumers.
