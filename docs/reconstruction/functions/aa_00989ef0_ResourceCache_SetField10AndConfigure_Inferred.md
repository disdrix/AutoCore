# Function record: ResourceCache_SetField10AndConfigure_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00989ef0` |
| **Canonical name** | `ResourceCache_SetField10AndConfigure_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00989ef0` |
| **Address** | `0x00989ef0`–`0x00989f58` (**105 B** / `0x69`) |
| **Module** | `autoassault.exe` |
| **System** | ResourceCache / guarded resource host |
| **Status** | Dual A/B sealed W31-F 2026-07-29 — **accept-with-gaps** |

## Purpose

Guarded write of host `+0x10` from ECX, then run configure on embedded `+0x14` (`FUN_00996d70`). Used from AssManager bootstrap on global `0x00d1eac8` and from a local ResourceCache-family object in `FUN_0099c1c0`.

## Signature

```c
// Retail: EDI=object; ECX=field10; stack configureFlag; RET 4; void
void ResourceCache_SetField10AndConfigure_Inferred(
    void* obj /*EDI*/,
    uint32_t field10 /*ECX*/,
    uint32_t configureFlag /*stack*/);
```

## Layout

| Off | Role |
|-----|------|
| `+0x10` | dword from ECX |
| `+0x14` | subobject for configure |
| `+0x68` | CRITICAL_SECTION |
| `+0x80` | CS-enable flag (byte) |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00989ef0_FUN_00989ef0.md` |
| Annotated | `docs/reconstruction/raw/aa_00989ef0_FUN_00989ef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ResourceCache_SetField10AndConfigure_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00989ef0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00989ef0_FUN_00989ef0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_00989ef0_ResourceCache_SetField10AndConfigure_Inferred.md`, `B_…` |
| Scratch | `docs/reconstruction/tmp/a_00989ef0.md` |

## Related

- `ResourceCache_LookupByName` (`0x00989e00`) — same CS/flag layout.
- W30-D: AssManager calls with EDI=`0x00d1eac8`, flag stack=0, ECX size-like.
