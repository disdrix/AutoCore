# Annotated low-level: CVOGHBAI_ProfileType4_ctor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005d7de0` |
| VA | `0x005d7de0`–`0x005d7df8` (25 B) |
| Canonical | `CVOGHBAI_ProfileType4_ctor_Inferred` |
| Ghidra | `FUN_005d7de0` |
| System | npc-ai / HBAI / profile-type-4 |
| Date | 2026-07-29 (W28-K re-seal; scaffold 2026-07-23) |

## Machine-level notes

- **Thin leaf ctor** for factory profile type word **4**:
  1. `FUN_005d1990(this, pOwner)` — mid HBAI base init (period −1000, attach, skill-timer block, hash scan, etc.; **not OWN**).
  2. Install subclass vtbl **`PTR_FUN_009db08c`**.
  3. Return `this`.
- Factory: `Object_EnsurePrimaryHBAI_FromAIProfile` case **4** → `new(0xC0)` + this ctor.
- DoLogic sibling sealed as `CVOGHBAI_ProfileType4_DoLogic_Inferred` @ `0x005d7ca0` (vtbl+0x50 / DATA `0x009db0dc`).
- **thiscall** + **`RET 4`**; no local SEH (base owns SEH).
- Ghidra decompile `FUN_005d1990(param_2)` omits explicit this — bytes keep **ECX=this** and push owner.

## Pseudocode (annotated)

```c
// __thiscall; RET 4; returns this
// size: factory new(0xC0)
void * __thiscall CVOGHBAI_ProfileType4_ctor_Inferred(void *self, void *pOwner)
{
  FUN_005d1990(self, pOwner);     // base mid ctor (thiscall)
  *(void **)self = &PTR_FUN_009db08c;
  return self;
}
```

## Open questions

- Product/PDB English class name for `009db08c` (structural ProfileType4 only).
- Full field map of base `FUN_005d1990` (separate unit).
- Whether type-4 is product "Mine"/other — **do not invent**; AICode factory table is a different path (`CVOGHBAI_CreateByAICode`).
