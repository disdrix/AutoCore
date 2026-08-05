# Review A (reconstruction fidelity): `aa_00547050` MissionDef_ParseObjectiveXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_00547050` |
| **VA** | `0x00547050` |
| **Canonical name** | `MissionDef_ParseObjectiveXml` (role-sealed; PDB open) |
| **Ghidra name** | `FUN_00547050` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00547050_MissionDef_ParseObjectiveXml.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested from GiveMission / CompleteObjective → `FUN_00547920` EnsureXml **`Objective`** tag |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Parse one mission **`<Objective>`** XML subtree and attach the resulting objective / requirement objects onto the mission def (`this` = mission def in EnsureXml call framing; decompiler shows stack `param_1` as XML node / iterator context):

1. SEH frame; large stack (`sub esp, 0x2b0`).
2. Query child nodes via COM/XML vtbl (`+0x44` / related).
3. **Sequence cap:** compare sequence index vs mission objective-count byte **`mission+0x130`**; on overflow log  
   **`"Mission - Sequence too big.. (%d >= %d) %s"`** and return.
4. Read objective fields (ID, etc.) with string helpers; log on missing id / id mismatch:
   - `"Mission - No objective ID %s"`
   - `"Mission - objective ID didn't match %s"`
   - `"Mission - objective lacking child nodes (%d) %s"`
5. Walk requirement child tags with `_wcsicmp` against UTF-16 type names; for each match:
   - `operator_new(size)`
   - construct requirement with parent objective slot from **`mission+0x13c[seq]`**
   - jump join
6. Requirement type switch (asm + string table + known ctor duals) includes at least:

| Wide type string | VA (string) | Alloc size | Ctor | Notes |
|---|---|---:|---|---|
| `kill_aggregate` | `0x009d0b44` | `0x48` | `0x00612c80` | |
| `collect` | `0x009d0b34` | `0x68` | `0x00611690` | dualed Collect type=2 |
| `deliver` | `0x009d0b24` | `0x24` | `0x00610bc0` | dualed Deliver type=3 |
| `money` | `0x009d0b18` | `0x14` | (next arm) | |
| `stunt` | `0x009d0b0c` | `0x1c` | `0x006101f0` | |
| `mission` | `0x009d0afc` | `0x28` | `0x0060fe80` | |
| `km` | `0x009d0af4` | `0x18` | `0x0060f0d0` | |
| `timeplayed` | `0x009d0adc` | `0x1c` | `0x0060e9f0` | |
| `patrol` | `0x009d0acc` | `0xd8` | `0x0060e090` | |
| `useitem` | `0x009d0abc` | `0x58` | `0x0060ced0` | |
| `characterlevel` | `0x009d0a9c` | `0x18` | `0x0060cb80` | |
| `escort` | `0x009d0a8c` | (later arms) | | string present in table |

Also callees: `FUN_006138a0` (kill family), `FUN_00610810`, `FUN_0060c0b0`, `FUN_0059d7*0` objective helpers, `_wtoi`, `SysFreeString`, `FUN_00799820` (sequence/size probe).

**Not** a free toast helper; **not** runtime objective evaluate.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00547050_FUN_00547050.md` |
| Annotated | `docs/reconstruction/raw/aa_00547050_FUN_00547050.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00547050.cpp` (scaffold; decompiler-truncated) |
| Function record | `docs/reconstruction/functions/aa_00547050_FUN_00547050.md` |
| Live | `batch_decompile` / `force_decompile` / `analyze_function_complete` @ `0x00547050` |
| Live bytes | `read_memory` prologue + type-string table `0x009d0a80+` |
| Asm arms | `get_assembly_context` on Collect/Deliver/stunt/… call sites |
| Callers | **Sole:** `FUN_00547920` @ xref `0x00547afe` |
| Sibling duals | Collect ctor `A_aa_00611690_*`, Deliver ctor `A_aa_00610bc0_*` (sole static callers inside this factory) |
| Parent | `A/B_aa_00547920_MissionDef_EnsureXmlLoaded` |

**Not performed:** full linear reconstruction of every switch arm in clean C++; `disassemble_bytes`; Launcher; CE.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = Objective XML parse / requirement factory | **High** | strings + ctors + sole EnsureXml Objective arm |
| Sequence vs `+0x130` gate | **High** | `"Sequence too big"` + `MOVZX` of `byte [EDI+0x130]` pattern |
| Slot array `+0x13c[seq]` as parent for ctors | **High** | asm LEA `[EDI+0x13c][EDX*4]` then PUSH owner |
| Collect / Deliver ctor mapping | **High** | dualed ctors + sole xrefs here |
| Full type→ctor table exhaustive | **Probable** | many arms recovered; residual untyped arms remain |
| Decompiler body complete | **Low / noise** | Ghidra marks bulk as “unreachable”; use asm+callees |
| Product PDB name | **Open** | leave inferred `MissionDef_ParseObjectiveXml` |
| clean ≡ full retail CF | **Open** | scaffold truncated; do not port from clean alone |

---

## 4. Control flow summary (evidence-backed)

```
ParseObjectiveXml(missionDef, objectiveXmlNode):
  children = xml vcalls
  if seq >= missionDef.objectiveCount(+0x130): log Sequence too big; return
  parse objective id / bind into missionDef.objectives(+0x13c)[seq]
  for each requirement child:
    match type wide-string
    alloc + Requirement_Xxx_ctor(owner=objSlot)
  release COM/BSTR
```

---

## 5. Gaps

1. Full ordered switch with every remaining ctor (`00610810`, `0060c0b0`, kill, escort, …) not line-audited.
2. Clean C++ still decompiler-truncated — treat dual+asm as authority.
3. Objective field fill helpers `FUN_0059d7xx` not dualed this batch.
4. Runtime hydrate capture open.

**Verdict:** **accept-with-gaps** — factory role, sequence gate, Collect/Deliver arms High; exhaustive type matrix Probable.
