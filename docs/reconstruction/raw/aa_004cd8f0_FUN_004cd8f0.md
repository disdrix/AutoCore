# Raw capture: FUN_004cd8f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd8f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cd8f0` |
| **Canonical name** | `FUN_004cd8f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_004cd8f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  void *pvVar1;
  undefined4 uVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a1eb7;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(undefined4 **)(param_1 + 0xe4fc) != (undefined4 *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)**(undefined4 **)(param_1 + 0xe4fc))(1);
    *(undefined4 *)(param_1 + 0xe4fc) = 0;
  }
  pvVar1 = operator_new(0x30);
  uStack_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005b3f60();
  }
  *(undefined4 *)(param_1 + 0xe4fc) = uVar2;
  uStack_4 = 0xffffffff;
  FUN_005b3fa0(param_2,param_3,param_4,*(undefined4 *)(*(int *)(param_1 + 0xe4f8) + 0x18),param_5);
  ExceptionList = pvStack_c;
  return;
}
```

---

## W38-S re-verify (2026-08-04)

**Tools:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs/callers + context duals W30-O / W37-L. **No** `disassemble_bytes`.

| Field | Value |
|---|---|
| Body | `0x004cd8f0`–`0x004cd991` exclusive (**161 B** / `0xA1`); pad `CC` |
| Ghidra meta | Entry `004cd8f0`, end `004cd990` (last byte inclusive) — **matches** exclusive end |
| ABI | `__thiscall`; ECX = **host**; stack **4 args** (3 floats + context*); void; **`ret 0x10`** (`c2 10 00`) |
| SEH | handler `LAB_009a1eb7`; FS:[0] frame |
| Classification | worker (host replace-owned-grid-obj) |
| Ghidra callers | **none** (0 CODE/DATA xrefs) — static orphan |

### Semantics (bytes authority for this=populate)

1. If `host+0xe4fc` non-null: **scalar-deleting dtor** `vtbl[0](1)` on owned 0x30; store **0**.
2. `operator_new(0x30)`; if non-null **`FUN_005b3f60`** default ctor (ECX=new, returns this); else null.
3. Store result at **`host+0xe4fc`**.
4. Call **`FUN_005b3fa0`** with:
   - **ECX = new object** (bytes: `mov ecx,eax` before call — decompiler drops this)
   - stack: `(dim_a, dim_b, dim_c, scale, ctx)` where:
     - dims = stack args 0..2 (`param_2..4`)
     - **scale** = `*(*(host+0xe4f8) + 0x18)` (from nested host, **not** stack)
     - **ctx** = stack arg 3 (`param_5`)
5. SEH epilog; `add esp,0x10` (locals); **`ret 0x10`**.

### Relative calls (from body)

| Site | Target | Role |
|---|---|---|
| `0x004cd925` | `operator_new` path (`e8 …`) after `push 0x30` | alloc |
| `0x004cd93f` | `FUN_005b3f60` | W30-O default ctor |
| `0x004cd97a` | `FUN_005b3fa0` | W37-L scaled grid populate |

### Full body hex (161 B)

```
6aff68b71e9a0064a100000000506489250000000051568bf18b8efce4000085c974108b016a01ff10c786fce40000000000006a30e868bffbff83c4048944240485c0c74424100000000074098bc8e81c660e00eb0233c08b8ef8e400008986fce400008b51188b4c2424518b4c242452518b4c2424895424108b54242852518bc8c7442424ffffffffe821660e008b4c24085e64890d0000000083c410c21000
```

### Notes

- Live path for 0x30 list host per W30-O / W37-L (vs dead convenience ctor `005b4260`).
- Sibling `FUN_004cd9a0` also stores at `+0xe4fc` but different gate/populate (`FUN_005b42f0`); **not** this unit.
- Zero static xrefs: may be dead, dynamically bound, or analysis-missing — body still sealed.
