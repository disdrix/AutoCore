# Annotated: CVOGObjectiveRequirement_Deliver_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_00610bc0` |
| VA | `0x00610bc0` |
| Canonical | `CVOGObjectiveRequirement_Deliver_ctor` |
| System | missions-progression |
| Date | 2026-07-29 |

## Machine-level notes

- Prefer image bytes when decompiler uses `undefined4*` scaling (`param_1 + 8` ⇒ offset **0x20**).
- Base `FUN_00637da0` runs first; Deliver vtable overwrites base vtable.
- Type dword at **+0x0c** is the requirement-class enum (Deliver = **3**).
- Byte **+0x23** default **1**; consumers treat **0** as quantity bypass (not set in this body except default).

## Image body (read_memory)

```text
8B442404 5650 8BF1 E8D3710200
B001 83C9FF
884620 884621 884622 884623
C706240F9E00
C7460C03000000
894E10 C7461400000000 894E18 894E1C
8BC6 5E C20400
```

## Pseudocode (refined)

```c
CVOGObjectiveRequirement_Deliver* __thiscall
CVOGObjectiveRequirement_Deliver_ctor(
    CVOGObjectiveRequirement_Deliver* this,
    void* owner)
{
  FUN_00637da0(this, owner);          // base; +0 vtable temp, +4 owner
  *(uint8_t*)((uint8_t*)this + 0x20) = 1;  // GiveItemAtStart
  *(uint8_t*)((uint8_t*)this + 0x21) = 1;  // TakeItemAtEnd
  *(uint8_t*)((uint8_t*)this + 0x22) = 1;  // NPCTargetCompletes
  *(uint8_t*)((uint8_t*)this + 0x23) = 1;  // require-count DEFAULT
  *(void**)this = &PTR_FUN_009e0f24;       // Deliver vtable
  *(int32_t*)((uint8_t*)this + 0x0c) = 3;  // type SEALED
  *(int32_t*)((uint8_t*)this + 0x10) = -1; // CBIDItem
  *(int32_t*)((uint8_t*)this + 0x14) = 0;  // NumToDeliver
  *(int32_t*)((uint8_t*)this + 0x18) = -1; // TargetNPCCBID
  *(int32_t*)((uint8_t*)this + 0x1c) = -1; // ContinentID
  return this;
}
```

## Identity

- RTTI: `.?AVCVOGObjectiveRequirement_Deliver@@` @ `0x00afe97c`
- XML: `Requirement type="deliver"`
- Contrast: Collect ctor `0x00611690` type **2** / vtable `009e12c4`

## Open questions

- Factory `FUN_00547050` full string→ctor dispatch table
- Original PDB method decoration beyond RTTI class
