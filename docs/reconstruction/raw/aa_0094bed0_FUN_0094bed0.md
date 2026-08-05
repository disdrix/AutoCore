# Raw capture: FUN_0094bed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094bed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094bed0` |
| **Canonical name** | `FUN_0094bed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * FUN_0094bed0(void)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  void *pvVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ab618;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x210);
  piVar3 = (int *)0x0;
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    piVar3 = (int *)FUN_00575440();
  }
  local_4 = 0xffffffff;
  pvVar1 = *(void **)(unaff_EDI + 0xe04);
  pvVar4 = DAT_00af30f4;
  (**(code **)(*piVar3 + 8))(DAT_00af30f4,pvVar1,1);
  FUN_00512160(puStack_8,local_4,1);
  (**(code **)(*piVar3 + 0x218))(*(undefined4 *)(unaff_EDI + 0xe04));
  iVar2 = FUN_004bc180(piVar3);
  if (iVar2 < 0) {
    (**(code **)*piVar3)(1);
    ExceptionList = pvVar4;
    return (int *)0x0;
  }
  ExceptionList = pvVar1;
  return piVar3;
}
```

---

## Live re-verify (2026-07-29 W30-K)

**Tools:** `decompile_function` + `read_memory` + `analyze_function_complete` + `get_xrefs_to` / callers / callees. **No** `disassemble_bytes`.

### Body

| Item | Value |
|---|---|
| Range | `0x0094bed0`–`0x0094bf8d` inclusive |
| Size | **190 B** / `0xBE` |
| Pad | `CC CC` then unrelated at `0x0094bf90` |
| Epilogue | dual exits both **`C2 08 00`** (`ret 8`) |

### Full body hex (190 B)

```
6aff6818b69a0064a100000000506489250000000051566810020000e8a1d9b3ff83c4048944240433f6897424103bc674098bc8e83795c2ff8bf0c7442410ffffffff8b8f040e00008b15f430af008b066a0151528bceff50088b44241c8b4c24186a0150518bcee82362bcff8b87040e00008b16508bceff92180200008b8f340d000056e82602b7ff85c07d1c8b166a018bceff1233c05e8b4c240464890d0000000083c410c208008b4c24088bc65e64890d0000000083c410c20800
```

### Byte-sealed ABI / CF (supersedes decompiler surface where conflict)

1. **EDI** = host/world context (live register; decompiler `unaff_EDI`).
2. **Stack** `(coid_lo, coid_hi)` — `ret 8`; sole caller `FUN_008119c0` @ `0x00811a0f` pushes `[esi+8]`, `[esi+0xc]` with `edi=ebx` (host).
3. SEH frame `LAB_009ab618`; EH state `−1` → `0` around ctor → `−1`.
4. `operator_new(0x210)` → `Object_009d33c4_Ctor` (`FUN_00575440`, W29-H) if non-null.
5. `vtbl+8(DAT_00af30f4, *(host+0xe04), 1)`.
6. `Object_SetCoidIdentity` / `FUN_00512160`(obj, coid_lo, coid_hi, 1) — stack formals, **not** SEH locals (decompiler residual).
7. `vtbl+0x218(*(host+0xe04))`.
8. `Object_RegisterListed` (`FUN_004bc180`) on listing `*(host+0xd34)` with obj; if return `< 0`: scalar-delete `vtbl[0](1)`, return `NULL`; else return obj.

### Relative calls (from bytes)

| Site | Target |
|---|---|
| `E8` @ `0x0094beec` | `operator_new` `0x00489892` |
| `E8` @ `0x0094bf04` | `FUN_00575440` `0x00575440` |
| `E8` @ `0x0094bf38` | `FUN_00512160` `0x00512160` |
| `E8` @ `0x0094bf55` | `FUN_004bc180` `0x004bc180` |

### Xrefs

| Kind | Site |
|---|---|
| CODE CALL (1) | `FUN_008119c0` @ `0x00811a0f` |

### Decompiler residuals (raw body above is historical surface)

- Signature `void` formals / missing EDI + `ret 8`.
- `FUN_00512160(puStack_8, local_4, 1)` — wrong args; true args are stack formals + flag `1`.
- ExceptionList restore assigned from `DAT_00af30f4` / `host+0xe04` — false; bytes restore SEH frame from stack.
- Null `operator_new` path still uses `*piVar3` (undefined; no explicit OOM return).
