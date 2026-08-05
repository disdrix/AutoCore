# Annotated low-level: FUN_004cb3e0

| Field | Value |
|---|---|
| Stable ID | `aa_004cb3e0` |
| VA | `0x004cb3e0` – `0x004cb409` |
| System | object pose / local pos float4 store |
| Date | 2026-07-23 scaffold; **2026-07-29 OWN-ONLY dual re-verify** |

## Machine-level notes (2026-07-29)

- `read_memory` @ `004cb3e0`: four scalar dword copies from stack arg into `ecx+0x240..+0x24c`, then `ret 4` (`c2 04 00`).
- No branches, no callees, no FPU ops — pure integer `mov` (bit-identical for f32).
- Callers (xrefs): `FUN_004c3a40` @ `004c3aa6` (after `test [..+0xb8],0xc7`); `FUN_005cd3b0` @ `005ce8a3` (SSE-built stack vec, `push edx`).
- Prefer assembly when decompiler conflicts — here decompile ≡ bytes ≡ raw.

## Pseudocode (annotated ≡ raw ≡ live)

```c
// __thiscall ECX=object, [esp+4]=float* / uint32_t* in
void __thiscall FUN_004cb3e0(int param_1, undefined4 *param_2)
{
  *(undefined4 *)(param_1 + 0x240) = *param_2;
  *(undefined4 *)(param_1 + 0x244) = param_2[1];
  *(undefined4 *)(param_1 + 0x248) = param_2[2];
  *(undefined4 *)(param_1 + 0x24c) = param_2[3];
  return;
}
```

## Machine bytes

```
8b 44 24 04  8b 10  89 91 40 02 00 00
8b 50 04     89 91 44 02 00 00
8b 50 08     89 91 48 02 00 00
8b 40 0c     89 81 4c 02 00 00
c2 04 00
```

## Dual

- A: `docs/reconstruction/reviews/A_aa_004cb3e0_CVOGObject_StoreLocalPosition4_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_004cb3e0_CVOGObject_StoreLocalPosition4_Inferred.md`

## Open questions

- Product English name (keep `_Inferred`).
- Full consumer inventory of `+0x240` (out of this leaf).
- Deep dual of bypass `FUN_005cd3b0`.
