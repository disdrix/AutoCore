# Review B (skeptical / adversarial): `aa_0092f710` Client_LoadKeymapIni

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f710` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-022 OWN-ONLY) |
| **Counterpart** | `reviews/A_aa_0092f710_Client_LoadKeymapIni.md` |
| **System** | input-drive-control |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | thiscall / ECX = client | **Falsified** — client is stack formal; `RET 4`; no ECX-as-this |
| 2 | Missing file is silent no-op | **Falsified** — fail path calls `FUN_007f9480` with path in **EAX** = `"keymap.ini"` and writes default file |
| 3 | Double `ActionMap_TrySetSlotBind` is a decomp bug / duplicate | **Falsified** — asm `XOR BL,BL` then `MOV BL,1` (primary then alt lanes); dualed peer already documents keymap.ini dual pass |
| 4 | Parses INI sections `[...]` like VOG.ini | **Falsified** — only `//` comments and `=;` tokens; no section headers |
| 5 | Uses ECX ActionMap as first formal without client base | **Falsified** — ActionMap is always `client+0x116c` derived |
| 6 | Many callers / hot reload each frame | **Falsified** — **1** UNCONDITIONAL_CALL from `Client_InitInstance` only |
| 7 | Product name must be `_Inferred` only | **Overstated** — literal `keymap.ini` + InitInstance Keymap plate + writer header seal product surface; method demangle still open but name not invented product API |
| 8 | Merges with `Client_LoadVogIniConfig` | **Falsified** — different path (`VOG.ini` vs `keymap.ini`), different keys, different sinks |
| 9 | Overwrites customized slots always | **Falsified** — bind write is dualed `ActionMap_TrySetSlotBind` which **gates** on customized flag==0 |
| 10 | `RET 0` / cdecl no cleanup | **Falsified** — both exits `C2 04 00` (`RET 4`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| fopen / path string | **High** | Wrong config surface |
| Fail → write-default | **High** | Missing default generation |
| Delimiters `//` `=;` | **High** | Parse corruption |
| Mode 0..3 find loop | **High** | Wrong slot group |
| BL dual-lane apply | **High** | Primary/alt swap or drop |
| ABI stack client + RET 4 | **High** | Stack smash |
| ActionMap @ +0x116c | **High** | Wrong object |
| Mode product English | **Tentative** | Docs only |
| Helper internals (9230/9480/db30) | **Med** (evidence-only) | Partial port |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
SUB ESP,0xc18
fopen("keymap.ini","r")
if NULL:
  EAX = client+0x116c; PUSH EAX
  EAX = "keymap.ini"
  CALL FUN_007f9480
  RET 4
load "//" and "=;"
loop fgets(0x800):
  strip //
  desc = strtok(=;)
  if strlen(desc) < 2: continue
  map = client+0x116c
  for mode=0..3:
    slot = FUN_007f9230(desc)  // EAX=mode ECX=map
    if slot: break
  if mode==4 or !slot: continue
  primary = strtok; optional alt = strtok
  parse primary; TrySetSlotBind lane0
  parse alt;     TrySetSlotBind lane1
fclose; RET 4
```

Live decompile ≡ raw CF. Asm corrects path-in-EAX fail path and BL lane pair. Clean `Client_LoadKeymapIni.cpp` carries both.

Caller seal: `Client_InitInstance` @ `0x0094a83b` only.

---

## 4. Surviving contract for AutoCore

```
// Boot-time only (InitInstance)
Client_LoadKeymapIni(client)
// ActionMap = client + 0x116c
// File format (writer documents):
//   Description Text=KEY;ALTKEY;
//   // comments; = and ; are field seps; + is mod join inside FUN_0092db30
// Missing file → emit default keymap.ini from current ActionMap bindings
// Bind apply never force-overwrites customized slots (flag gate in TrySetSlotBind)
// RET 4; not thiscall
```

Port notes:

- Keep dual-lane apply (primary then alt) or alt binds from keymap.ini are dropped.
- Keep customized-flag gate in `ActionMap_TrySetSlotBind` or user binds wipe on reload.
- Do not merge with VOG.ini loader.

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/product path. Residual gaps are undualed helpers + mode English + runtime → **accept-with-gaps** (aligned with A). No reject-class conflict.
