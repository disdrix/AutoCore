# Function record: `Object_LoadOrReplaceAnimSlot`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005828b0` |
| **Canonical name** | `Object_LoadOrReplaceAnimSlot` (structural) |
| **Ghidra name** | `FUN_005828b0` |
| **Address** | `0x005828b0` |
| **Body** | `005828b0`–`005829c6` (through `ret 0xC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client::special-event` / visual anim |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W18-C)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Prior scaffold: `FUN_005828b0`
- Prior auto-alias: `Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_005828b0`
- Call-context: INC airlift `.anm` load on visual CBID `0xadc`

## Purpose

Replace visual host anim slot `[slotIndex]` with a newly constructed `0x78` slot loaded from path; register with controller at `this+0x24`; return `1` success / `0` fail.

## Signature

```c
uint32_t __thiscall Object_LoadOrReplaceAnimSlot(
    VisualAnimHost *self,
    int slotIndex,
    const char *path,
    uint8_t flagByte);
// epilogue: ret 0xC
```

## Host offsets

| Off | Field |
|----:|-------|
| `+0x24` | controller* (`vtbl+0x0C` add, `+0x10` remove) |
| `+0x2c` | `AnimSlot*` table base |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005828b0_FUN_005828b0.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_005828b0_FUN_005828b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_LoadOrReplaceAnimSlot.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005828b0.cpp` |
| Prior named scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_005828b0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_005828b0_Object_LoadOrReplaceAnimSlot.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005828b0_Object_LoadOrReplaceAnimSlot.md` |
| Scaffold record | `docs/reconstruction/functions/aa_005828b0_FUN_005828b0.md` (superseded) |

## Callers / callees

**Callees:** `operator_new/delete`, `FUN_0074ed90`, `FUN_0074eb20`, `FUN_0074ecf0`, `FUN_00989e00`, `FUN_0074ee40`, `FUN_0079a110`, `FUN_0074e910`, controller vtbl `+0x0C`/`+0x10`

**Callers (direct):**

| Symbol | VA | ECX source |
|--------|-----|------------|
| `ClientSpecialEvent_TeleportIn_ctor` | `0x00978d20` | visual `@ event+0x24` |
| `ClientSpecialEvent_TeleportOut_ctor` | `0x009781d0` | visual `@ event+0x10` |
| `FUN_00979310` | `0x00979310` | visual `@ +0x10` |

## Confidence

| Claim | Level |
|---|---|
| thiscall `ret 0xC` / 3 stack args | **Confirmed** |
| `this` = visual (not special-event shell) | **Confirmed** (call-site `mov ecx`) |
| Replace + 0x78 alloc + load gate + add | **Confirmed** |
| Product type names / flag English | **Open** |
| Duration source policy (`DAT_00b04c74+0x238`) | **High** (bytes); product meaning **Open** |
