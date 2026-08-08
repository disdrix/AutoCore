# Review A (reconstruction fidelity): `aa_0051b350` ServerCreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b350` |
| **VA** | `0x0051b350` |
| **Body** | `0x0051b350`–`0x0051b54e` (**510 bytes** / `0x1FE`); pad `CC` @ `0x0051b54f` |
| **Canonical name** | `ServerCreateFromPacket` |
| **Prior scaffold** | `FUN_0051b350` |
| **Review date** | `2026-08-04` (WQ9R-I dual seal) |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0051b350_ServerCreateFromPacket.md` |
| **System** | object-spawn / network create (client) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + string list + callees. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Server → client object materialization from a create packet:**

1. Profiler zone `"ServerCreateFromPacket"`.
2. Unpack **CBID** (4) + **COID** (8) from stream.
3. Optional **CBID remap** via int-key map on `DAT_00b041fc+4`.
4. `CVOGReaction_GiveItemByCbid` factory → `vtbl+8` CBID init with host.
5. Stamp COID at `obj+0x160/+0x164`, flag `+0x168=1`, then `vtbl+0x20` COID/identity init (passes stream).
6. On remap hit: `obj+0x17c |= 0x80`. Return object*.
7. On COID failure: log, drain child list via `vtbl+0x2B0`, return null.

Related family: `AllocateNewObjectFromCbid` (`0x004cf120`) uses same factory + `vtbl+8` but no packet COID path / different success flags (`+0x17c |= 0x10`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x0051b350` |
| Entry / mid / epilogue bytes | `read_memory` @ `0x0051b350`, `0x0051b380`, `0x0051b400`, `0x0051b520`–`0x0051b54f` |
| Strings | `"ServerCreateFromPacket"` @ `0x009cee68`; three Invalid* plates |
| Profiler | dualed `Profiler_EnterNamedZone` (`RET 4` thiscall) — site listed in its A review |
| Unpack | `FUN_00787d40` thiscall stream |
| Map | `Map_LowerBoundFindByIntKey` @ `0x0050f940` |
| Factory | `CVOGReaction_GiveItemByCbid` |
| Sibling spawn | `AllocateNewObjectFromCbid` clean dual W18-T |
| Xrefs | **none** recovered (pointer / missed site — gap) |
| Raw / clean | `aa_0051b350_*`, `ServerCreateFromPacket.cpp` |

**Not performed:** Launcher, live create-packet capture, parent ledgers.

---

## 3. Sealed facts

### 3.1 ABI / body

| Claim | Evidence | Confidence |
|---|---|---|
| Body **510 B** (`0x1FE`) end `0x0051b54e` | bounds + epilogue `ADD ESP,0x2C` / `C3` / pad `CC` | **Confirmed** |
| Stack **arg0 = stream***, **arg1 = host*** | `MOV EDI,[ESP+0x3c]` after SEH; `MOV ECX,[ESP+0x40]` for vtbl+8 host | **Confirmed** |
| Caller-clean (**bare RET**) | epilogue no `RET 8` | **Confirmed** |
| Returns **object*** / **null** in EAX | `MOV EAX,ESI` success; `XOR`/0 fail paths | **Confirmed** |
| SEH + profiler enter/leave all exits | enter string; leave @ success label + fail tail | **Confirmed** |

### 3.2 Packet + remap

| Step | Detail | Confidence |
|---|---|---|
| Unpack CBID 4 B | `PUSH 4` / `LEA` dst / `MOV ECX,EDI` / `FUN_00787d40` | **Confirmed** |
| CBID == -1 → null | `CMP [local],-1` / early leave | **Confirmed** |
| Unpack COID 8 B | `PUSH 8` second unpack | **Confirmed** |
| Map on `DAT_00b041fc+4` | `MOV ESI,[DAT_00b041fc]`; `LEA ECX,[ESI+4]` | **Confirmed** |
| **unaff_EDI is false** | Bytes: `XOR BL,BL` … on hit `MOV BL,1`; map takes **2** stack args | **Confirmed** |
| Remap value `node+0x10` | `MOV ECX,[EAX+0x10]`; store over local CBID | **Confirmed** |

### 3.3 Object fields / vcalls

| Offset / slot | Role | Confidence |
|---|---|---|
| Factory `CVOGReaction_GiveItemByCbid` | allocate by CBID | **Confirmed** |
| `vtbl+8(cbid, host, 1)` | CBID init | **Confirmed** (same family as AllocateNewObjectFromCbid) |
| `obj+0x160/+0x164` | COID lo/hi (`piVar3[0x58]/[0x59]`) | **Confirmed** (bytes `MOV [ESI+0x160]`) |
| `obj+0x168 = 1` | identity present flag byte | **Confirmed** |
| `vtbl+0x20(coid_lo, coid_hi, 0, stream, 1)` | COID init | **Confirmed** |
| `obj+0x17c \|= 0x80` if remapped | success flag bit | **Confirmed** |
| Fail: log + `vtbl+0x2B0` list + scalar-delete + `FUN_00403430` | cleanup | **High** (CF sealed; list node layout partial) |

### 3.4 Product naming

| Claim | Confidence |
|---|---|
| Name **`ServerCreateFromPacket`** | **High** — profiler zone plate + COID error suffix `(in ServerCreateFromPacket)` |
| Not skill-bank cast | **High** — object factory/create path |

---

## 4. Control flow: clean ≡ raw ≡ live (semantic)

| Stage | Match |
|---|---|
| Profiler enter/leave | Yes |
| CBID/COID unpack sizes | Yes |
| Map remap + 0x80 flag | Yes (clean fixes unaff_EDI trap) |
| Factory + vtbl+8 / +0x20 | Yes |
| COID stamp before identity vcall | Yes |
| Fail list drain | Yes (structure; exact list this-adjust gap) |
| Return obj* / null | Yes |

---

## 5. Gaps / open

1. **No Ghidra xrefs** — call site(s) likely register/indirect; not sealed.
2. Product type of stream / host / remap map value column.
3. Exact child-list node layout for `vtbl+0x2B0` fail path.
4. Whether bare RET implies free function vs custom convention in all TUs.
5. Runtime / bit-exact / differential — open.
6. Full SEH state machine on fail (local_4 = 1) — behavior preserved, not fully annotated.

**Verdict:** **accept-with-gaps**
