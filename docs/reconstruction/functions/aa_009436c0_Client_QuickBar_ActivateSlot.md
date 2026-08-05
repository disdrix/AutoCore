# Function record: Client_QuickBar_ActivateSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_009436c0` |
| **Canonical name** | `Client_QuickBar_ActivateSlot` |
| **Address** | `0x009436c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual (2026-07-29)** — packing, type-5 window, mode-1 page, callee roles sealed as High/Inferred; product enum string open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Quick-bar activate dispatcher: `(slot, mode, page)`. Mode 1 selects page; else type switch skill / item / chat-macro bank. Vehicle-host-visible path remaps slots 0/1 to skill-slot cast or primary/secondary weapon fire.

## Signature (decompiler-derived)

```c
/* QuickBar activate: (slot, mode, page). page=-1 → UI+0x50c. index=slot+page*10.
   type@client+0x3220+idx*0x18: 1=cast skill, 2=item use, 5=chat-macro bank.
   mode 1 → page select. On-foot +0x6b9: slot0/1 → skill slot or weapon fire. */
void Client_QuickBar_ActivateSlot(char nSlot, char nMode, char nPage); // client in EAX
```

## Residual seals (2026-07-29)

| Topic | Result |
|---|---|
| Packing `(idx*3+0x645)*8` | ≡ `0x3220+idx*0x18+8` (**High**) |
| Type-5 `+3000` / `0xfffff447` | `int64(payload)+3000 ∈ [0,14]` macro row (**High**) |
| Type-5 product | Chat-macro bank via `DAT_00d177c8` + `0x2021` send — **not** combat power |
| Mode 1 | Page select `FUN_008a0ed0` (shift-QB) |
| Callee roles | SelectPage / TryPrimaryFire / UseInventoryItem / SendChatOrMacro (**_Inferred**) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009436c0_Client_QuickBar_ActivateSlot.md`
- Annotated: `docs/reconstruction/raw/aa_009436c0_Client_QuickBar_ActivateSlot.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_QuickBar_ActivateSlot.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_009436c0_Client_QuickBar_ActivateSlot.md`
- Dual B: `docs/reconstruction/reviews/B_aa_009436c0_Client_QuickBar_ActivateSlot.md`
- Scratch: `tmp/a_009436c0.md`

## Callers / callees

| Direction | Symbol / addr | Role |
|---|---|---|
| Caller | `Client_Input_PollBoundActions` `0x00925d60` | QB `(i,0,-1)`; shift-QB `(i,1,-1)` |
| Callee | `Client_CastSkillFromQuickBarSlot` `0x009418e0` | type 1 |
| Callee | `Client_QuickBarActivateSkillSlot` `0x00921b50` | on-foot 0/1 |
| Callee | `Input_TryFireSecondaryWeapons` `0x0091a550` | slot1 off-foot |
| Callee | `FUN_00922270` | slot0 off-foot primary / hardpoint |
| Callee | `FUN_008a0ed0` | mode-1 page select |
| Callee | `FUN_005710c0` | cargo find by COID |
| Callee | `FUN_00941d50` | use-item (0x2045) |
| Callee | `FUN_00941fb0` | chat/macro (0x2021) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packing / type-5 window math | High |
| Type-5 = chat-macro bank | High (table) / Probable (product word) |
| Callee product symbols | Inferred |
| Runtime | Open |
