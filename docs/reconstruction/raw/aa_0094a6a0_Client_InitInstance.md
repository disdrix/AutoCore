# Raw capture: Client_InitInstance

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094a6a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094a6a0`–`0x0094b324` |
| **Canonical name** | `Client_InitInstance` |
| **Ghidra name** | `FUN_0094a6a0` |
| **System** | `client-boot` / InitInstance |
| **Capture timestamp** | `2026-07-29` (W18-H dual A/B) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + callers |
| **Integrity** | Full decompile body in scaffold `aa_0094a6a0_FUN_0094a6a0.md` (2026-07-23); live re-verify **≡** (no CF delta) |

---

## Authority

- **Authoritative full raw body:** `docs/reconstruction/raw/aa_0094a6a0_FUN_0094a6a0.md`
- **Live re-verify section:** same file, W18-H append
- Do not fork a second full body; named plate is the dual-seal summary + ABI/phase seal.

---

## Signature (sealed)

```c
// __stdcall: client app object on stack; return BOOL-like int in EAX; RET 4
// Caller: FUN_0094ba40 → Client_InitInstance(&DAT_00d1a840)
uint32_t __stdcall Client_InitInstance(void *clientApp /* param_1 */);
// Success path returns 1. Graphics init failure calls _exit(1) and does not return.
```

---

## Byte seal (read_memory)

| Region | Bytes / note |
|---|---|
| Entry | `55 8B EC 6A FF 68 D0 BE 9B 00 64 A1 …` EBP+SEH |
| First work | load `[ebp+8]` → EDI; test `+0x3c10` LED path |
| First string path | call through `FUN_007a4400` with `"Client InitInstance"` |
| Exit | `B8 01 00 00 00` … restore FS:[0] … `C2 04 00` (**RET 4**) |

---

## Phase map

See scaffold re-verify (W18-H). High-signal gates:

| Gate | Effect |
|---|---|
| `client+0x3c10 != 0` | LED_FX startup / later LED teardown |
| `FUN_00948530() != 0` | graphics fail → `_exit(1)` |
| `client+0x31f5 == 0` | full data tables + generators + some asset post-init |
| `client+0x31f5 != 0` | skip those batches (light / alternate boot) |
| always | return **1** on normal completion |

---

## Product identity

String evidence seals **InitInstance** product role:

- `"Client InitInstance"`
- `"@@Finish of InitInstance"` / `"InitInstance::done"`
- Phase banners: render engine, sector map, clonebaselist, physics, sound, UI

Not a table-only loader — it **is** the client boot InitInstance orchestration (tables are one gated phase).

