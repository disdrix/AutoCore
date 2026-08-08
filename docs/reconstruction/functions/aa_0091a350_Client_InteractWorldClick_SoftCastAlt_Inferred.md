# Function record: Client_InteractWorldClick_SoftCastAlt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091a350` |
| **Canonical name** | `Client_InteractWorldClick_SoftCastAlt_Inferred` |
| **Ghidra name** | `FUN_0091a350` |
| **Address** | `0x0091a350`–`0x0091a54a` inclusive (**507 B** / `0x1FB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | MEGA-033 (parent dual `0x00925820` Client_InteractWorldClickHub) |
| **Completion status** | **Dual A/B sealed 2026-08-05 (MEGA-033)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; terminal false) |

## Alias

- Ghidra / scaffold: `FUN_0091a350`
- No `Named_CalleeOf_*` scaffold present for this VA

## Purpose

When dualed **`Client_InteractWorldClickHub`** takes the **non-drop** branch (`DAT_00d1a860 == 0`), run the soft-cast / clear-select **alternate**:

1. Gate `client->vtbl+0x3D8()`; fail → return false.
2. `client+0x558 = -1.0f` (`DAT_00aaa668`); `client+0xA32 = 0`; `client->vtbl+0x478()`.
3. If select entity at `client+0x758`: `Ui_ResolveEntityNameColor_Inferred` (ECX=entity, ctx `&DAT_00d1a840`).
4. If global character soft-cast flag `entity+0x106`: clear `+0x107`; if body visual `+0x284`, spawn type-2 FX via residual `FUN_007a0120` on FX host from `DAT_00d17944`.
5. Return true.

Does **not** zero `select[+0x758]` or call `FUN_0093e120(0)` — hub ItemPickup sibling owns that clear-select.

## Signature

```c
// ESI = Client* (caller MOV ESI,EDI); no stack args; bare RET (C3); bool AL
uint8_t Client_InteractWorldClick_SoftCastAlt_Inferred(void /* ESI=client* */);
```

| Field | Offset / value | Conf |
|---|---|---|
| float cancel | `client+0x558` ← **-1.0f** | **Confirmed** |
| flag clear | `client+0xA32` ← 0 | **Confirmed** |
| select entity | `client+0x758` | **Confirmed** |
| FX float arg | `client+0x548` | **Confirmed** |
| soft-cast gate/clear | `entity+0x106` / `+0x107` | **Confirmed** |
| body visual | `entity+0x284` | **Confirmed** |

## Call chain (evidence only; residual callees not dualed here)

```text
Client_InteractWorldClickHub  (0x00925820)  [dualed W17-C]
  ├─ … modal gates (vtbl+0x3D8 on UI globals) …
  ├─ DAT_00d1a860 == 0:
  │    └─ FUN_0091a350  Client_InteractWorldClick_SoftCastAlt_Inferred  [OWN MEGA-033]
  │         ├─ vtbl+0x3D8 / vtbl+0x478
  │         ├─ FUN_00930fc0  Ui_ResolveEntityNameColor_Inferred  [dualed WQ9D-J]
  │         └─ FUN_007a0120  FX spawn type-2  [residual]
  └─ DAT_00d1a860 != 0:
       ├─ drop-destroy modal (char+0xCD0) OR
       └─ ray + soft-cast hit-list walk (sort MEGA-116, resolve MEGA-028, …)
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0091a350_FUN_0091a350.md` |
| Annotated | `docs/reconstruction/raw/aa_0091a350_FUN_0091a350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InteractWorldClick_SoftCastAlt_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0091a350.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0091a350_Client_InteractWorldClick_SoftCastAlt_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0091a350_Client_InteractWorldClick_SoftCastAlt_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_0091a350_FUN_0091a350.md` |
| Report | `docs/agents/task-dual-ab-0091a350-mega-033-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / single caller | **Confirmed** |
| Non-drop soft-cast alternate role | **High** |
| Soft-cast +0x107 clear + type-2 FX | **High** |
| Product vtbl / flag English | **Inferred** |
| Runtime | **Open** |
