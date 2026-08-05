# Raw capture: NDResource_LoadByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423ac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00423ac0` |
| **Canonical name** | `NDResource_LoadByKey` |
| **System** | `nd-resource` |
| **Capture timestamp** | `2026-07-23` (scaffold); re-decompile seal `2026-07-29` |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Body below is authoritative decompile; do not overwrite casually — append versioned sections if needed |

---

## Raw pseudocode (authoritative decompile)

```c
/* NDResource_LoadByKey

   Resolve resource via NDResourceCache_LookupOrCreate(DAT_00d1f050, key, ...).
   Calls virtual method +4 on result (init/load).
   Returns: -1 if null, else 0/1 from init bool.
   NOTE: NDXml_LoadDocumentFromPath treats only <0 as error, so init-fail (0) still enters Release
   path. */

uint NDResource_LoadByKey
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;

  uVar2 = FUN_00423b10();
  piVar3 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,param_2,uVar2,param_3,param_4);
  *param_1 = piVar3;
  if (piVar3 == (int *)0x0) {
    return 0xffffffff;
  }
  cVar1 = (**(code **)(*piVar3 + 4))();
  return (uint)(cVar1 != '\0');
}
```

---

## Machine body (`read_memory` @ `0x00423ac0`, 2026-07-29)

```
56 e8 4a 00 00 00 8b 4c 24 14 8b 54 24 10 51 8b 0d 50 f0 d1 00
52 50 8b 44 24 18 50 51 33 f6 e8 bc a0 33 00 85 c0 8b 54 24 08
89 02 75 07 83 c8 ff 5e c2 10 00 8b 10 8b c8 ff 52 04 84 c0 74 05
be 01 00 00 00 8b c6 5e c2 10 00
```

- Ends with **`ret 0x10`** (stdcall, 4 stack args).
- Callees: `FUN_00423b10` @ `0x00423b10`, `NDResourceCache_LookupOrCreate` @ `0x0075dba0`.
- Sole code xref: `NDXml_LoadDocumentFromPath` @ `0x007b6d8a`.
