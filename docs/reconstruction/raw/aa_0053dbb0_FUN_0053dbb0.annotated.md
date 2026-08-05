# Annotated low-level: CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0053dbb0` |
| VA | `0x0053dbb0`–`0x0053dcf6` (327 B) |
| Ghidra | `FUN_0053dbb0` |
| Named (INFERRED) | `CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred` |
| System | object lifecycle / AI mode apply |
| Date | 2026-07-29 (W26-E dual seal) |
| Downstream | `WorldObj_RebindActivate` (`00560e90`); `CVOGObject_SwitchHBAIByCode` (`005d4440`) |

## Machine-level notes

- Source: live `decompile_function` + `read_memory` (no `disassemble_bytes`).
- ABI: **thiscall** ECX = **CVOGObject***; stack **char modeFlag**; **`ret 4`**.
- **Virtual method** — 8 rdata vtable slots; no direct function-to-function callers in analyze.
- Mode branch:
  - `0`: self vtbl **+0x10**
  - nonzero: self vtbl **+0xc**, stamp `*(worldObj+0x28)=0x10`, fan-out children vtbl+8(4)
- Always rebind world obj via `FUN_00560e90(worldObj, 1)` when host present.
- Dual locked AI callbacks on `*(worldObj+0x3c)` slots **+0x50 / +0x54** with global `DAT_00b04610`.
- Conditional AI switch (tail-call `005d4440`): codes **1** (flag==0) or **6** (flag!=0) when object lacks both `obj+0x40` and `obj+8`.

## Pseudocode (annotated)

```c
// thiscall CVOGObject*; char modeFlag; ret 4; virtual
void CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred(
    CVOGObject *self /*ECX*/, char modeFlag /*stack+4*/)
{
  WorldObj *wo = (WorldObj *)self->field_08; // param_1[2]
  if (wo == NULL)
    return;

  if (modeFlag == 0) {
    self->vtbl[+0x10/4](self);
  } else {
    self->vtbl[+0x0C/4](self);
    *(uint32_t *)((char *)wo + 0x28) = 0x10;
    if (self->field_0C /* child list */) {
      // count = list.vtbl+0x4c(); items = list.vtbl+0x50();
      // for i in [0,count): child[i]->vtbl+8(4)
    }
  }

  WorldObj_RebindActivate_Inferred(wo, 1); // FUN_00560e90 → unbind+bind+flag

  // locked AI notify pair on *(wo+0x3c):
  //   lock FUN_005070b0 / optional FUN_005070d0
  //   AI vtbl+0x50(&DAT_00b04610)
  //   same for vtbl+0x54

  // needsSwitch ≡ (wo+0x40==0) || (wo+8==0)
  if (needsSwitch) {
    if (modeFlag == 0)
      CVOGObject_SwitchHBAIByCode(self, 1); // tail
    else
      CVOGObject_SwitchHBAIByCode(self, 6); // tail
  }
}
```

## Sealed residuals

| Claim | Confidence |
|---|---|
| thiscall + char flag + ret 4 | **High** |
| Virtual (rdata xrefs only) | **High** |
| Rebind always when host present | **High** |
| Tail SwitchHBAI 1 vs 6 | **High** (bytes JMP `0x005d4440`) |
| needsSwitch reduces to missing flag/host | **High** (CF algebra) |
| Product English for modeFlag / stamp 0x10 | **Medium** |
| Child notify arg `4` product meaning | **Tentative** |
| Runtime / bit-exact | **Open** |

## Open questions

1. Which CVOG subclasses install this slot (8 vtables).
2. Product name for mode flag 0 vs nonzero (active vs passive? combat vs idle?).
3. Why AI codes 1 and 6 specifically (normal family vs WalkingCreatureTurreted).
