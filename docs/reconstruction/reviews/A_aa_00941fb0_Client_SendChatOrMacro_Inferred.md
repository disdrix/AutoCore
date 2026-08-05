# Review A (reconstruction fidelity): `aa_00941fb0` Client_SendChatOrMacro_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941fb0` |
| **VA** | `0x00941fb0` |
| **Canonical name** | `Client_SendChatOrMacro_Inferred` |
| **Review date** | `2026-07-29` (dual A/B — seal opcode **0x2021**) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00941fb0_Client_SendChatOrMacro_Inferred.md` |
| **System** | chat / sector-broadcast |
| **Verdict** | **accept-with-gaps** (static opcode + dual wire paths **sealed**; runtime open) |

---

## 1. Purpose

Unified client **chat / macro send** helper. Builds either:

1. **Sector C2S `Broadcast` `0x2021`** → `Client_SendSectorPacket` (`client+0xc78`), or  
2. **Global C2S `Chat` `0x8000`** → `FUN_008073b0` (`client+0xc7c`),

selected by **chat-type** (`param_4`) and, for convoy (type 3), a character flag. Used by quick-bar chat-macro bank, bound-action macro edges, slash/command helpers, and chat UI.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00941fb0_FUN_00941fb0.md` |
| Annotated | `docs/reconstruction/raw/aa_00941fb0_FUN_00941fb0.annotated.md` (+ 2026-07-29 residual seal) |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendChatOrMacro_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00941fb0_Client_SendChatOrMacro_Inferred.md` |
| Live decompile | Ghidra `decompile_function` `0x00941fb0` |
| Live bytes | Ghidra `read_memory` `0x00941fb0` (prologue + body); `0x00af9218`; `0x00a28b7c` |
| Jump table | `read_memory` `0x0094239c` (15-byte type→group map) |
| Callees (role only) | `Client_SendSectorPacket` `0x00807460`; `FUN_008073b0` global send |
| Server mirror | `BroadcastPacket.cs` (`0x2021`), `ChatPacket.cs` (`0x8000`), `ChatType.cs` |

---

## 3. Sealed residuals

### 3.1 Calling convention — **SEALED**

Prologue / epilogue (`read_memory` @ `0x00941fb0`):

```
push ebp / mov ebp,esp / and esp,-16 / sub esp,0xC34
mov edi, edx          ; param_2 = message*
xor ebx, ebx
mov esi, ecx          ; param_1 = recipient/target name*
...
ret 0x0C              ; 3 stack dwords
```

| Slot | Role |
|------|------|
| **ECX** | `param_1` — C-string copied into **private-recipient / target name** field (17 B) |
| **EDX** | `param_2` — message C-string (required non-null, non-empty) |
| **`[ebp+8]`** | `param_3` — client/game host* (`+0xe98` character, `+0xc78` sector conn, `+0xc7c` global conn, `+0x30e8/+0x30ec` rate stamp) |
| **`[ebp+0xc]`** | `param_4` — **ChatType** (int) |
| **`[ebp+0x10]`** | `param_5` — bool: run pre-send filters `FUN_0093bd10` + `FUN_00865970`; enable PM UI side-path |

Empty/null message → **`0x80070057`** (`mov eax,0x80070057` / decomp `-0x7ff8ffa9`).

### 3.2 Channel enable mask — **SEALED**

```
eax = 1 << (param_4 & 0x1f)
if ((DAT_00af9218 & eax) == 0) return 0;
```

`read_memory DAT_00af9218` = **`0xFFFFFFFF`** in this image (all low 32 type bits allowed). Disable-bit → silent `0`.

### 3.3 Opcode **0x2021** (sector Broadcast) — **SEALED**

| Fact | Evidence |
|---|---|
| Imm store | `C7 84 24 .. 21 20 00 00` → `mov dword [pkt], 0x2021` |
| Default type seed | adjacent `mov dword [pkt+4], 5` then overwritten with `param_4` on sector arms |
| Send API | `Client_SendSectorPacket(client, (short)msgLen + 0x29, &pkt_2021)` |
| Conn | `client+0xc78` (per `Client_SendSectorPacket` plate) |

### 3.4 Sector packet layout (`local_808` base) — **SEALED** (static stores)

| Off | Width | Content | Store in body |
|----:|------:|---------|---------------|
| `+0x00` | 4 | opcode | **`0x2021`** |
| `+0x04` | 4 | ChatType | `param_4` (seeded 5, then `local_804 = iStack_c1c`) |
| `+0x08` | 8 | SenderCoid | char multi-inherit `adj+0x164` / `+0x168`, else **`0xFFFFFFFF_FFFFFFFF`** |
| `+0x10` | 1 | IsGM | **`0`** |
| `+0x11` | 1 | pad | **unwritten** (matches server skip-1) |
| `+0x12` | 2 | MessageLength | `strlen(message)` as `short` |
| `+0x14` | 17 | Sender name | **not written** in this function (stack residual) |
| `+0x25` | … | Message | copy of message incl. NUL (`local_7e3`) |

Send size: **`MessageLength + 0x29`**.  
Server `BroadcastPacket.Read` (opcode already stripped): ChatType u32, SenderCoid u64, IsGM, pad1, MessageLength i16, Sender 17, Message null-string — **field order matches** client `+0x04…` relative to opcode.

### 3.5 Opcode **0x8000** (global Chat) — **SEALED** companion path

| Fact | Evidence |
|---|---|
| Imm store | `mov dword [esp+…], 0x8000` on `uStack_c20` |
| Type | `iStack_c1c = param_4` at `+0x04` |
| IsGM | `0` at `+0x08` |
| Recipient 17 | copy of **ECX** `param_1` → `local_c17` |
| Sender 17 | character name via vtbl `+0x160` (or `"DEBUG"` if no char) → `local_c06` |
| MessageLength | `strlen` at `uStack_bf4` low word; text at `+2` |
| Send | `FUN_008073b0(msgLen + 0x31, &uStack_c20)` when global gate true |
| Conn | `client+0xc7c` vtbl`+0x18` |

Matches AutoCore `ChatPacket` / `GameOpcode.Chat = 0x8000`.

### 3.6 ChatType → path switch — **SEALED**

Jump map @ `0x0094239c` (index = `type - 1`, types 1…15):

| Group | Types | Path |
|------:|-------|------|
| 0 | 1, 2, 4, 13, 14, 15 | **Global `0x8000`** (`FUN_00807370` gate → `FUN_008073b0`) |
| 1 | 3 | **Convoy special**: if `*( *(adj+0xa8) + 0xf6 ) == 0` → global; else **sector `0x2021`** |
| 2 | 5, 8, 9, 10 | **Sector `0x2021`** + stamp `client+0x30e8=GetTickCount()`, `+0x30ec=msgLen` |
| 3 | 6, 7, 11, 12 | **No send** (fall through → `return 1`) |

Product enum (`ChatType.cs`): 1 GlobalPublic, 2 PrivateMessage, 3 ConvoyMessage, 4 ClanMessage, 5 SectorMessage, 8 LFC, 9 Trade, 10 Local, 13 Faction, 14/15 Sector FR/DE.  
**Note:** types **14/15** use **global** path despite “Sector*” names.

### 3.7 Pre-send filters (`param_5 != 0`) — **SEALED** as gates

1. `local_c38 = FUN_0093bd10(client, &global_pkt)` — non-zero → early return that code (command/macro rewrite residual).  
2. `FUN_00865970()` — side effect before switch.  
3. Type **2** + `param_5`: zero a 0x3f8 buffer, `FUN_007a75e0`, optional `FUN_008f8200(DAT_00d1b8dc, 7, recipient, buf, 0)` PM UI.

### 3.8 Returns — **SEALED**

| Code | Meaning |
|------|---------|
| `0x80070057` | null/empty message |
| `0` | channel bit off **or** send helper “false” paths that still return 0 from callees |
| `local_c38` | prefilter error |
| send-helper result | from `FUN_008073b0` / `Client_SendSectorPacket` |
| `1` | message non-empty but no network send (disabled case / gate fail fallthrough) |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ABI ECX/EDX + 3 stack / `ret 0x0C` | **High** | prologue + epilogue bytes |
| Opcode imm **`0x2021`** | **High** | machine imm |
| Sector size **`msgLen+0x29`** | **High** | `add eax,0x29` before call |
| Sector layout offsets §3.4 | **High** | local frame map + server mirror |
| Global opcode **`0x8000`** + size **`msgLen+0x31`** | **High** | imm + decomp |
| Type→path table §3.6 | **High** | decomp cases + jump-table bytes |
| Coid from char `+0x164/+0x168` (MI adj) | **High** | both sector arms |
| Sender **17** filled on sector wire | **Open** | **not stored** here |
| `FUN_0093bd10` / `FUN_00865970` semantics | **Open** | outside unit |
| Exact global pad vs size +2 residual | **Open** | size formula sealed; pad math soft |
| Runtime capture | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| null/empty → `0x80070057` | **Yes** |
| channel mask `DAT_00af9218` | **Yes** |
| build both pkt templates; copy msg/names | **Yes** |
| optional prefilter; switch by type | **Yes** |
| sector arms pack coid + `SendSectorPacket` | **Yes** |
| global arms `FUN_008073b0` | **Yes** |

---

## 6. Gaps / open

1. Sector **Sender** 17-byte field never written — server may ignore C2S sender and force connection name.  
2. Semantics of `FUN_0093bd10` (slash-command rewrite?) and `FUN_00865970`.  
3. Why send size is `+0x29` / `+0x31` vs minimal header+NUL (2–3 B slack).  
4. Call-site full arg recovery (many parent decompiles show 3-arg skeletons; true ABI is 5-slot).  
5. Live wire dump of `0x2021` / `0x8000` C2S.

**Verdict:** **accept-with-gaps** — **opcode 0x2021 sealed** with dual-path layouts, type switch, ABI, and sizes; sender fill + prefilter bodies + runtime remain open.
