# Function record: stoChunkStreamWindow_ReadCString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436f10` |
| **Canonical name** | `stoChunkStreamWindow_ReadCString` |
| **Prior / Ghidra name** | `FUN_00436f10` |
| **Address** | `0x00436f10`–`0x00436f7b` (**108 B** / `0x6C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` stream window |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (W38-D OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00436f10`
- Scaffold: `Named_CalleeOf_Named_assId_00436f10` (**reject** as product alias)
- Binary null-terminated string peer of text `FUN_0076a200`

## Purpose

Binary-mode **NUL-terminated C-string** reader into `std::string`:

1. `string::resize(out, 0)` — clear destination.
2. Require `cursor + base < streamEnd` (`window+0x14`).
3. Loop: if `available < cursor+1`, call ensure `FUN_00435df0(window, base+cursor)`; fail if hr < 0 or available < 1.
4. Read 1 byte from `window+0x18+cursor`; advance cursor by 1.
5. If byte is `NUL`, return **0** (terminator consumed, not appended).
6. Else `operator+=(out, char)` and continue while `cursor+base < streamEnd`.
7. Hit streamEnd without NUL → return **−1**.

Entry takes the **window** in **ESI** (callers usually pass `reader+0x14`) and dest string in **EDI**.

## Signature (sealed)

```c
// ESI = StoStreamWindow*, EDI = std::string* out, bare RET
// Returns 0 success, 0xffffffff fail.
int32_t stoChunkStreamWindow_ReadCString(/* ESI window */, /* EDI out */);
```

## Window fields

| Off | Role |
|---:|---|
| `+0x04` | cursor |
| `+0x08` | base |
| `+0x0c` | available |
| `+0x14` | streamEnd (absolute stop) |
| `+0x18` | data buffer base |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00436f10_FUN_00436f10.md` |
| Annotated | `docs/reconstruction/raw/aa_00436f10_FUN_00436f10.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkStreamWindow_ReadCString.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_00436f10.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00436f10_stoChunkStreamWindow_ReadCString.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00436f10_stoChunkStreamWindow_ReadCString.md` |
| Function alias | `docs/reconstruction/functions/aa_00436f10_FUN_00436f10.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `std::string::resize` | IAT `[0x009c6308]` |
| Callee | `FUN_00435df0` | `0x00435df0` ensure/refill (not owned) |
| Callee | `std::string::operator+=` | IAT `[0x009c6294]` |
| Caller | `FUN_00439a20` | mode wrapper (binary → this; text → `FUN_0076a200`) |
| Caller | many binary unserialize paths | 50+ xrefs (phyBone, effEffect, …) |

## Confidence

| Claim | Level |
|---|---|
| CF: clear → streamEnd loop → ensure → read → NUL/append → 0/−1 | **High** |
| ESI=window, EDI=string*, bare RET | **High** |
| Window field map + streamEnd gate | **High** |
| Binary-mode role (peer of text string reader) | **High** |
| Product English (CString vs StringZ) | **Probable** |
| Ensure full semantics | **Out of scope** |
| Runtime / bit-exact | **Open** |
