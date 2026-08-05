# Review A (reconstruction fidelity): `aa_0091f6b0` Client_Input_TryUseModChip

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091f6b0` |
| **VA** | `0x0091f6b0` |
| **Canonical name** | `Client_Input_TryUseModChip` (INFERRED; prior `FUN_0091f6b0` / DriveControlTick-callee scaffold) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0091f6b0_Client_Input_TryUseModChip.md` |
| **System** | `input-drive-control` (skill cast side-path) |
| **Verdict** | **accept-with-gaps** — mod-chip CF + opcode **`0x202c`** + dual callers **sealed** |

---

## 1. Purpose

Client **mod-chip use attempt** from input (and a UI sibling). On success (or when `player+0x6b9` is already armed), sends sector packet **opcode `0x202c`** size **`0x18`** carrying the local character **TFID** at multi-inherit **`+0x164`**. On missing chip, shows **"You have no mod chip!"**. On LocalCastValidate failure, formats and optionally toasts the skill failure string.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0091f6b0_FUN_0091f6b0.md` (+ 2026-07-29 residual) |
| Annotated | `docs/reconstruction/raw/aa_0091f6b0_FUN_0091f6b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_TryUseModChip.cpp` |
| Function record | `docs/reconstruction/functions/aa_0091f6b0_Client_Input_TryUseModChip.md` |
| Live decompile | Ghidra `decompile_function` `0x0091f6b0` — body ≡ raw |
| Full asm | Ghidra `disassemble_function` `0x0091f6b0` |
| Immediates | `read_memory` `@0x0091f6e3` (`0x98967f`), `@0x0091f6fd`/`0x0091f7ac` (`0x202c`), string `@0x00a2f888` |
| Call-site asm | `get_assembly_context` `@0x00923666`, `@0x008c5132` |
| Callee | `FUN_0040ce50` decompile (sole caller = this unit) |
| Parent map | `Client_Input_DriveControlTick` raw `DAT_00d1cafa`/`cafb` edge |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| `EDX` = client object | Body `MOV [EDX+0xc2c],0x98967f`; DriveControlTick `MOV EDX,EBX` before CALL |
| ECX / `param_1` unused | No arg use of ECX in body |
| `RET` (no stack args) | Epilogue `ADD ESP,0x118; RET` |
| Void side-effect unit | No post-call return consume at DriveControlTick site |

### 3.2 Entry gates + sentinel — **SEALED**

```
player = DAT_00d1b6d8 != 0
*(DAT_00d1b644 + 0xf5) == 0
*(player + 0x6bb) == 0
→ *(client + 0xc2c) = 9999999 (0x98967f)
```

### 3.3 Dual send paths + opcode `0x202c` — **SEALED**

| Path | Condition | Validate? | Send |
|---|---|---|---|
| A | `player+0x6b9 != 0` | **No** | `0x202c` + TFID@`+0x164` |
| B | vehicle@`+0x250` and `FUN_0040ce50 != -1` and `LocalCastValidate==0` | **Yes** | same |
| Toast modal | no vehicle or ce50 == −1 | — | `"You have no mod chip!"` |
| Toast log | validate ≠ 0 and `DAT_00d1b8dc` | — | FormatFailureMessage |

Assembly seals **both** opcode stores (`0x0091f6fd`, `0x0091f7ac`) — decompiler second-path stack naming is non-authoritative for the opcode write.

### 3.4 Packet — **SEALED** (static)

| Off | Content |
|----:|---------|
| +0 | `u32` **`0x202c`** |
| +4 | **unwritten** by this unit (4B gap) |
| +8 | 16B TFID from char multi-inherit `+0x164` |
| size | **`0x18`** via `Client_SendSectorPacket` |

### 3.5 `FUN_0040ce50` — **SEALED** role (this unit)

- `this` = vehicle (`player+0x250`).
- If `vehicle+0x270 == 0` → return **`-1`**.
- Else nested multi-inherit walk to dword at **`…+0x3bc`** (mod-chip skill binding).
- **Sole** production caller is `0x0091f6b0`.

### 3.6 LocalCastValidate integration — **SEALED**

```
skill = FUN_0040ce50(vehicle)
skipBusy = (*(char(**)())(char_vtbl + 0x234))()
rc = Skill_LocalCastValidate(char_adj, /*target*/0, skipBusy, skill)
// rc == 0 → allow (prior dual aa_0051a790)
```

### 3.7 Callers — **SEALED** (two)

| Site | Parent | Precondition sketch |
|---|---|---|
| `0x00923666` | `Client_Input_DriveControlTick` | `DAT_00d1cafa && DAT_00d1cafb`; clear `cafb`; `EDX=client` |
| `0x008c5132` | `FUN_008c50f4` | UI; if not (`+0x6b8 && !+0x6b9` skill path) then `DAT_00d1b778` vtbl`+0x3d8` |

No other xrefs (`get_function_xrefs`).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF clean ≡ raw ≡ live decompile | **High** | Sectioned clean preserves branches |
| Opcode `0x202c` both paths | **High** | `read_memory` immediates |
| String-driven mod-chip role | **High** | `"You have no mod chip!"` |
| Validate 0 = allow | **High** | Prior LocalCastValidate dual |
| `client+0xc2c` stamp always on gate pass | **High** | Asm first write after gates |
| Packet +4 field | **Open** | Unwritten — residual |
| Flag English (`+0x6b9/6bb`, `+0xf5`) | **Tentative** | Structural only |
| Product symbol / opcode name | **Open** | INFERRED name only |
| Runtime | **Open** | Not executed |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Triple gate → stamp `+0xc2c` | Yes |
| `+0x6b9` bypass send | Yes |
| No vehicle / ce50 −1 → modal | Yes |
| Validate → send / format toast | Yes |
| No invented branches | Yes |

**Verdict:** **accept-with-gaps**
