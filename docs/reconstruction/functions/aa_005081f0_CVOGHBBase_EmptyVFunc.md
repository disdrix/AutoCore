# Function record: CVOGHBBase_EmptyVFunc

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081f0` |
| **Canonical name** | `CVOGHBBase_EmptyVFunc` |
| **Ghidra name** | `FUN_005081f0` |
| **Address** | `0x005081f0` |
| **Body range** | `0x005081f0`–`0x005081f0` (1 byte `c3`; exclusive end `0x005081f1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / shared empty leaf |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005081f0_CVOGHBBase_EmptyVFunc.md`, `reviews/B_aa_005081f0_CVOGHBBase_EmptyVFunc.md` |
| **Last reviewed** | `2026-07-29` (W18-A) |

## Alias

- `FUN_005081f0` (Ghidra)
- `Named_CalleeOf_CVOGHBOKToCastAgain_OnEnd_005081f0` (auto parent-seed — **misleading as sole role**; prefer EmptyVFunc)
- Residual alias `CVOGHBBase_EmptyVFunc_ret`

## Purpose

Shared **empty leaf**: single-byte `RET`. Observed roles via xrefs only:

1. **Base HB vtbl +0x14** default empty method (`PTR` @ `0x009cdab0` + 0x14).
2. **Tail target** from subclass OnEnd implementations (e.g. OKToCastAgain clears cast flag then `jmp` here).
3. Other CALL sites that need a thiscall-shaped nop.

Not Stop/detach, not resource free, not list remove.

## Signature

```c
void CVOGHBBase_EmptyVFunc(void);  // bare ret; ignores any this / stack args
```

## Algorithm

1. `return;`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005081f0_FUN_005081f0.md`
- Annotated: `docs/reconstruction/raw/aa_005081f0_FUN_005081f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_EmptyVFunc.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005081f0.cpp`
- Prior named plate: `reconstructed-exact/Named_CalleeOf_CVOGHBOKToCastAgain_OnEnd_005081f0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00435df0-005081f0-w18a-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none |
| **Callers** | DATA: base + many HB vtbls at +0x14; CODE: OnEnd tails (`0x0051e3c6`, token OnEnd, etc.), misc CALL sites |
| **DATA sample** | Base HB vtbl `0x009cdac4` (= `0x009cdab0+0x14`) = `f0 81 50 00` |

## Confidence

| Claim | Level |
|---|---|
| Body is pure `ret` (`c3`) | **High** |
| No side effects | **High** |
| Base vtbl +0x14 default | **High** |
| Not mass `EmptyRet` `0x0056f570` | **High** |
| Not neighbor empty `0x005081e0` | **High** |
| Product/PDB symbol | Open |
| Slot English name “OnEnd” for +0x14 | **Inferred / contested with +0x10** — behavior sealed as empty |

## Related

- `aa_005081c0` CVOGHBBase_Start
- `aa_005081d0` CVOGHBBase_Stop (tails **vtbl+0x10**, not this VA)
- `aa_00508200` CVOGHBBase_ctor
- `aa_0051e3b0` CVOGHBOKToCastAgain_OnEnd (tails here)
- `aa_0056f570` EmptyRet (different shared empty)
