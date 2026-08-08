# Annotated low-level: CVOGHBSkill_PossessCreature_DefaultFactory_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0054cbb0` |
| VA | `0x0054cbb0`–`0x0054cc02` (83 B / `0x53`) |
| Ghidra | `FUN_0054cbb0` |
| Canonical (inferred) | `CVOGHBSkill_PossessCreature_DefaultFactory_Inferred` |
| System | skills-abilities |
| Date | 2026-08-05 (R12-023 dual seal; scaffold 2026-07-23) |
| Parent dual | `0x00626240` `CVOGHBSkill_PossessCreature_ctor` (R11-021) |

## Machine-level notes

- Source: raw capture + live R12-023 re-verify (`decompile_function`, `analyze_function_complete`, `read_memory`, xrefs).
- Prefer assembly when decompiler conflicts; this leaf matches bytes.
- **No code CALL xrefs** — reached only as DATA function pointer @ `0x009d1bec` (type/vtable-adjacent factory slot).
- Class identity from dualed parent RTTI + shared vtbl `0x009d1ba4` + size `0x6f0`.
- Role is **default factory**, not full ctor: does **not** call `CVOGHBSkill_PossessCreature_ctor`, does **not** dyn-cast creature, does **not** clear `+0x6c0/6c4/6c8/6c9`.

## Pseudocode (annotated)

```c
// cdecl, no args, bare RET; EAX = CVOGHBSkill_PossessCreature* or null
// Object size 0x6f0; subclass vtbl PTR_FUN_009d1ba4
void *CVOGHBSkill_PossessCreature_DefaultFactory_Inferred(void)
{
  void *p;
  /* SEH: LAB_009a43fb; state -1 → 0 after operator_new */

  p = operator_new(0x6f0);                 /* push 0x6f0 */
  if (p == 0) {
    return 0;
  }
  CVOGHBSkillBase_DefaultCtor(p);          /* FUN_00578830 thiscall ECX=p
                                              installs base vtbl 0x009d3fdc */
  *(void **)p = &PTR_FUN_009d1ba4;         /* overwrite with PossessCreature vtbl */
  return p;
}
```

## ABI / layout seal

| Item | Evidence | Conf |
|---|---|---|
| No stack args / bare `RET` | terminal `C3` @ `0x0054cc02` | **High** |
| Size `0x6f0` | `68 F0 06 00 00` | **High** |
| Base default ctor | rel call → `0x00578830` (dualed) | **High** |
| Subclass vtbl | `C7 06 A4 1B 9D 00` | **High** |
| Null-new → null | `JZ` skip path; EAX=0 | **High** |
| DATA factory slot | dword @ `0x009d1bec` = entry | **High** |
| Class product name | parent RTTI Confirmed | **High** (inherited) |
| Method English "DefaultFactory" | structural | **Inferred** |

## Call graph (OWN only dualled)

```text
[DATA 0x009d1bec] ──ptr──► FUN_0054cbb0  DefaultFactory  [OWN R12-023]
                              ├─ operator_new(0x6f0)
                              ├─ CVOGHBSkillBase_DefaultCtor (0x00578830)  [dualed W23-S]
                              └─ *p = vtbl 0x009d1ba4

Sibling full-arg path (not this leaf):
  site 0x006263ab: operator_new(0x6f0) → CVOGHBSkill_PossessCreature_ctor (0x00626240)
```

## Open questions

- Who reads the factory dword @ `0x009d1bec` / type-registry dispatch English (non-OWN).
- Whether any indirect CALL sites exist beyond the single DATA pointer (reachability open).
- Runtime / bit-exact / differential.
