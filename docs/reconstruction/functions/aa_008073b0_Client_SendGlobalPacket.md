# Function record: Client_SendGlobalPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_008073b0` |
| **Canonical name** | `Client_SendGlobalPacket` |
| **Address** | `0x008073b0`–`0x008073ee` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | network-global |
| **Completion status** | **Human-refined** + dual A/B seal 2026-07-29 (W18-B); runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Xref count** | 50+ (Ghidra unconditional CALL sample) |

## Alias

- Ghidra: `FUN_008073b0`
- Prior scaffold: `Named_CalleeOf_Client_OnGlobalForceQuitDialog_008073b0`
- Sibling: `Client_SendSectorPacket` (`aa_00807460`, `client+0xc78`)

## Purpose

Generic C2S **global** transport via `client+0xc7c`:

1. If conn null → **`E_FAIL` (`0x80004005`)**.
2. If `conn->vtbl[+0x08]()` is false → **`E_FAIL`**.
3. Else `conn->vtbl[+0x18](0xFFFFFFFF, buffer, (int)size, 0)` → return **0**.

Used by global chat `0x8000`, modal dismiss `0x8006`, force-quit, and other global/UI C2S builders.

## Signature (sealed)

```c
// ESI = client* (NOT ECX); stack short size, void* buffer; ret 8
uint32_t Client_SendGlobalPacket(short size, void *buffer /* ESI=client */);
```

| | Global (this unit) | Sector sibling |
|---|---|---|
| Register | **ESI** | **ECX** thiscall |
| Conn | `+0xc7c` | `+0xc78` |
| Ready check | vtbl+0x08 | none |
| Null | E_FAIL | silent 0 |
| Flags | **0** hardcode | `~(EAX>>2)&2` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008073b0_FUN_008073b0.md` (+ versioned residual 2026-07-29)
- Annotated: `docs/reconstruction/raw/aa_008073b0_FUN_008073b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SendGlobalPacket.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_008073b0.cpp`
- Reviews: `A_aa_008073b0_Client_SendGlobalPacket.md`, `B_aa_008073b0_Client_SendGlobalPacket.md`

## Callers / callees

| Direction | Address / name | Notes |
|-----------|----------------|-------|
| Callee | conn vtbl+0x08 | ready/connected bool |
| Callee | conn vtbl+0x18 | send(mask, buf, size, flags) |
| Caller | `Client_SendChatOrMacro` `0x00941fb0` | global Chat `0x8000` |
| Caller | `Client_DismissModalPrompt` `0x007fc360` | opcode `0x8006` size `0x18` |
| Caller | force-quit / UI global builders | many |

## Confidence

| Claim | Level |
|---|---|
| ESI client + ret 8 + size short | **High / Sealed** |
| `+0xc7c` / vtbl+8 gate / vtbl+0x18 send | **High / Sealed** |
| E_FAIL vs 0 returns | **High / Sealed** |
| flags hardcode 0 | **High / Sealed** |
| Product conn type name | **Tentative** |
| Runtime / bit-exact | **Open** |
