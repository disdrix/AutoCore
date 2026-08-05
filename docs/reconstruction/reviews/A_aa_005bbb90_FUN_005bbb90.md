# Review A (reconstruction fidelity): `aa_005bbb90` FUN_005bbb90

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbb90` |
| **VA** | `0x005bbb90` |
| **Canonical name** | `FUN_005bbb90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005bbb90_FUN_005bbb90.md` |
| **System** | client object / skill host — active-flag notify from FX host list `+0x1E0` |
| **Verdict** | **accept** — store flag + on/off branches **sealed** |

---

## 1. Purpose

**Notify a subscribed object** (payload from FX host list `this+0x1E0` in `FUN_004b8dc0`) that the host active flag changed.

1. Always write **`*(this+0x7F8) = newFlag`** (`param_2`).
2. **If flag non-zero (activate):**
   - Zero **`this+0x804`**.
   - **`this+0x810 = this+0x8FC`** (copy a float/timer source).
   - If **`this+0x989 & 0x10`**: also **`this+0x808 = this+0x900`** and return.
3. **If flag zero (deactivate):**
   - Only if: `this+0x900 >= DAT_00aaa66c` **and** `*(this+4)+0x28 != 4` **and** `param_3 == 0`:
   - Walk list **`this+0xA24`**: for each payload `node[2]`, clear **`+0x16C`** and **`+0x170`** to 0.

`param_3` is the second stack arg forwarded from `FUN_004b8dc0` (often 0 from weapon path).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005bbb90_FUN_005bbb90.md` |
| Annotated | `docs/reconstruction/raw/aa_005bbb90_FUN_005bbb90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005bbb90.cpp` |
| Function record | `docs/reconstruction/functions/aa_005bbb90_FUN_005bbb90.md` |
| Live decompile | Ghidra `batch_decompile` `0x005bbb90` — ≡ raw |
| Live bytes | Ghidra `read_memory` `0x005bbb90` length 120 |
| Callers | `FUN_004b8dc0` list `+0x1E0` walk (and any other notify sites) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: `this` in **ECX** |
| Args | **`char newFlag`**, **`char param_3`** |
| Ret | **`ret 8`** (`C2 08 00`) — two stack args cleaned |

```c
void __thiscall FUN_005bbb90(void *this, char newFlag, char param_3);
```

### 3.2 Algorithm — **SEALED**

```
this+0x7F8 = newFlag
if (newFlag != 0):
  this+0x804 = 0
  this+0x810 = this+0x8FC
  if (this+0x989 & 0x10):
    this+0x808 = this+0x900
  return
else: // deactivate
  if (this+0x900 >= DAT_00aaa66c
      && *(int*)(*(this+4)+0x28) != 4
      && param_3 == 0):
    for node in list(this+0xA24):
      p = node[2]
      p+0x16C = 0; p+0x170 = 0
return
```

### 3.3 Layout fields — **SEALED (touched)**

| Off | Role |
|---|---|
| `+0x7F8` | **active mirror** of host notify flag |
| `+0x804` | cleared on activate |
| `+0x808` | set from `+0x900` when bit `+0x989&0x10` |
| `+0x810` | set from `+0x8FC` on activate |
| `+0x8FC` / `+0x900` | float/timer sources (SSE `movss`) |
| `+0x989` bit4 (`0x10`) | short-circuit activate path after `+0x808` write |
| `+0xA24` | list cleared on conditional deactivate |
| `*(this+4)+0x28` | mode int; value **4** skips deactivate list clear |

### 3.4 Entry machine bytes — **SEALED**

```
8A 44 24 04             mov  al, [esp+4]       ; newFlag
84 C0                   test al, al
88 81 F8 07 00 00       mov  [ecx+0x7F8], al
74 2F                   jz   → deactivate path
F6 81 89 09 00 00 10    test byte [ecx+0x989], 0x10
8B 81 FC 08 00 00       mov  eax, [ecx+0x8FC]
0F 57 C0                xorps xmm0, xmm0
F3 0F 11 81 04 08 00 00 movss [ecx+0x804], xmm0
89 81 10 08 00 00       mov  [ecx+0x810], eax
74 5F                   jz   → skip +0x808 path (bit clear)
8B 91 00 09 00 00       mov  edx, [ecx+0x900]
89 91 08 08 00 00       mov  [ecx+0x808], edx
C2 08 00                ret  8
; deactivate:
F3 0F 10 05 6C A6 AA 00 movss xmm0, DAT_00aaa66c
0F 2F 81 00 09 00 00    comiss xmm0, [ecx+0x900]
...
```

Hex prefix:  
`8a44240484c08881f8070000742ff68189090000108b81fc0800000f57c0f30f118104080000898110080000...`

### 3.5 Side effects — **SEALED**

- Always writes **`+0x7F8`**.
- Activate resets timer/state slots; may stamp **`+0x808`**.
- Deactivate may zero child entries `+0x16C/+0x170` under multi-condition gate.
- **`param_3 != 0`** suppresses deactivate list clear entirely.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| store `+0x7F8` | Yes |
| activate vs deactivate split | Yes |
| bit `0x10` early return | Yes |
| deactivate multi-gate + `+0xA24` clear | Yes |
| `ret 8` | Yes |

---

## 5. Gaps / open

1. Product type of `this` (character / weapon component / reaction host).
2. Meaning of `DAT_00aaa66c` threshold and mode `== 4`.
3. Semantic of child fields `+0x16C/+0x170`.
4. Runtime verification not run.

**Verdict:** **accept**
