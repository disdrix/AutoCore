# Review A (reconstruction fidelity): `aa_004b6fc0` FUN_004b6fc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6fc0` |
| **VA** | `0x004b6fc0` |
| **Canonical name** | `FUN_004b6fc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004b6fc0_FUN_004b6fc0.md` |
| **System** | client special-FX host — post-activate secondary list play-request |
| **Verdict** | **accept** — gate + list walk + 0xC8 payload copy **sealed** |

---

## 1. Purpose

**Post-activate follow-up** for the FX host (called from `FUN_004b8dc0` activate path after `FUN_004b7e50`).

If **`this+0x1FC != 0`**, walk intrusive list at **`this+0x1F8`**. For each node payload `node[2]`:

1. Copy **0x32 dwords (0xC8 bytes)** from the payload into a stack buffer.
2. Call **`FUN_00720d40()`** (interface-sound singleton getter).
3. Call **`FUN_00720670()`** (play/request on that subsystem; decompiler drops args — see gaps).
4. Debug log: `"Requesting play %s\n"` via `FUN_007a4480` with the original payload pointer.

If `+0x1FC == 0` or the list is empty, no-op return.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004b6fc0_FUN_004b6fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_004b6fc0_FUN_004b6fc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004b6fc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004b6fc0_FUN_004b6fc0.md` |
| Live decompile | Ghidra `batch_decompile` `0x004b6fc0` — ≡ raw |
| Live bytes | Ghidra `read_memory` `0x004b6fc0` length 48 |
| Callees | `FUN_00720d40`, `FUN_00720670`, `FUN_007a4480` |
| Callers | `FUN_004b8dc0` activate path (primary chain) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__fastcall` / thiscall-style**: `this` in **ECX** (`push ecx`; `mov [esp+0x10], ecx`) |
| Stack args | **none** |
| Entry | `51 83 B9 FC 01 00 00 00` — push ecx; `cmp dword [ecx+0x1FC], 0` |

```c
void __fastcall FUN_004b6fc0(void *this);
```

### 3.2 Algorithm — **SEALED**

```
if (this+0x1FC == 0) return
head = this+0x1F8
for node = *head; node != head; node = *node:
  payload = node[2]
  stackCopy[0..0x31] = *(dword*)payload   // 0x32 dwords
  FUN_00720d40()
  FUN_00720670()   // play request (args from stack copy / singleton — decompile partial)
  log "Requesting play %s\n" with payload
return
```

### 3.3 Layout fields — **SEALED (host)**

| Off | Role |
|---|---|
| `+0x1F8` | secondary FX/sound list head (same list deactivated by `004b8dc0` when flag off) |
| `+0x1FC` | **gate** for this walk (and for deactivate `+0x1F8` path in `004b8dc0`) |

Payload size implied: **≥ 0xC8** bytes copied.

### 3.4 Entry machine bytes — **SEALED**

```
51                      push ecx
83 B9 FC 01 00 00 00    cmp  dword ptr [ecx+0x1FC], 0
53 55 56 57             push ebx/ebp/esi/edi
89 4C 24 10             mov  [esp+0x10], ecx
74 4C                   jz   → epilogue
8B 81 F8 01 00 00       mov  eax, [ecx+0x1F8]
8B 18                   mov  ebx, [eax]
3B D8                   cmp  ebx, eax
74 40                   jz   → empty list exit
...
8B 6B 08                mov  ebp, [ebx+8]   ; payload = node[2]
81 EC C8 00 00 00       sub  esp, 0xC8
B9 32 00 00 00          mov  ecx, 0x32      ; dword count
8B F5                   mov  esi, ebp       ; rep movsd source
```

Hex prefix:  
`5183b9fc0100000053555657894c2410744c8b81f80100008b183bd874408bff8b6b0881ecc8000000b9320000008bf5`

### 3.5 Side effects — **SEALED**

- **Does not** mutate host flags or the list structure.
- May start secondary plays via `00720d40` / `00720670`.
- String evidence: `"Requesting play %s\n"` — product intent is **request play** of named secondary entries.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `+0x1FC` gate | Yes |
| list `+0x1F8`, payload `node[2]` | Yes |
| 0x32-dword copy | Yes |
| 00720d40 + 00720670 + log | Yes |

---

## 5. Gaps / open

1. Exact ABI/args into `FUN_00720670` (decompiler elides; likely stack-buffer / singleton `this`).
2. Product type of payload entries on `+0x1F8` vs primary list `+0x1EC`.
3. Runtime verification not run.

**Verdict:** **accept**
