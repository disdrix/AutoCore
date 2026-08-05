# Function record: CNDAssetStringTable_LoadFromStream_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099c1c0` |
| **Canonical name** | `CNDAssetStringTable_LoadFromStream_Inferred` |
| **Address** | `0x0099c1c0`–`0x0099c29b` (**220 B** / `0xDC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CND asset string table |
| **Completion status** | **Dual A/B present** — W37-I |
| **Bit-for-bit / runtime / diff** | Open |
| **Verdict** | **accept-with-gaps** |

## Alias

| Name | Notes |
|---|---|
| `FUN_0099c1c0` | Ghidra |
| `CNDAssetStringTable_LoadFromStream_Inferred` | Canonical (Inferred wrapper English; Unserialize is product plate) |

## Purpose

Temporary-host loader for **CNDAssetStringTable::Unserialize**: guard null stream, build host (`PTR_FUN_00a983b4` + ResourceCache-family body), configure (`field10=0x4000`, flag `1`), unserialize from stream, tidy vector + destroy host, return AL.

## Signature (sealed)

```c
uint8_t CNDAssetStringTable_LoadFromStream_Inferred(StreamReader *stream);
// RET 4
```

## Artifacts

- Raw / annotated / clean / dual A/B — see `aa_0099c1c0_FUN_0099c1c0.md`
- Agent report: `docs/agents/task-dual-ab-00968a50-0099c1c0-w37i-report.md`

## Related

- Product: `CNDAssetStringTable_Unserialize` (`0x0099bba0`, W34-J)
- Serialize twin: `0x0099b8e0`
- Configure helper: `ResourceCache_SetField10AndConfigure_Inferred` (`0x00989ef0`, W31-F)
- Caller stage gate: `FUN_004d73c0` with RAII `FUN_0099c140` / `FUN_0099c130`
