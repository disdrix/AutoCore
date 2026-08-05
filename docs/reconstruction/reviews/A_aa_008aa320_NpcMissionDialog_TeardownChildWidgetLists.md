# Review A (reconstruction fidelity): `aa_008aa320` NpcMissionDialog_TeardownChildWidgetLists

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa320` |
| **VA** | `0x008aa320` |
| **Body** | `0x008aa320`–`0x008aa3ef` exclusive (**207** B) |
| **Canonical name** | `NpcMissionDialog_TeardownChildWidgetLists` |
| **Prior / alias** | `FUN_008aa320` |
| **Review date** | `2026-07-29` (W21-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md` |
| **System** | missions-progression / client UI |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis / assembly context (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

On the **NPC mission dialog** (ESI), walk **two** dynamic child-widget pointer vectors and for each non-null entry:

1. Call **child `vtbl+0x440`** (destroy/close-style virtual — same slot index as Flush on the dialog itself).
2. Call **dialog `vtbl+0xb0(child)`** (host remove/detach).

Used exclusively from `Client_MissionDialog_FlushPreparedResponse` after optional 0x206E wire flush / reward UI cleanup, **before** dialog `vtbl+0x3ac` and `FUN_00792490`.

Does **not** clear `dialog+0x650` prepared response buffer, zero vector begin/end, or free vector storage.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008aa320_FUN_008aa320.md` (+ W21-T append) |
| Annotated | `docs/reconstruction/raw/aa_008aa320_FUN_008aa320.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NpcMissionDialog_TeardownChildWidgetLists.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_008aa320.cpp` |
| Function record | `docs/reconstruction/functions/aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md` |
| Live decompile | ≡ raw (two vectors; dual virtuals) |
| Live body bytes | `read_memory` @ `0x008aa320` length 220 |
| Parent dual | `aa_008ab8f0` Client_MissionDialog_FlushPreparedResponse |

---

## 3. Byte seal (`read_memory` @ `0x008aa320`)

```
8b 86 2c 07 00 00   mov eax, [esi+0x72c]     ; vec1 begin
85 c0               test eax, eax
53 55 57            push ebx, ebp, edi
…                   ; count = (end-begin)>>2 when begin≠0
ff 92 40 04 00 00   call [edx+0x440]         ; child virtual
… 50 8b ce
ff 92 b0 00 00 00   call [edx+0xb0]          ; dialog virtual (ECX=ESI)
…
8b 86 3c 07 00 00   mov eax, [esi+0x73c]     ; vec2 begin
…                   ; same loop pattern
5f 5d 5b c3         pop edi; pop ebp; pop ebx; ret
```

| Claim | Evidence | Conf |
|---|---|---|
| ESI dialog base | all loads `[esi+imm]`; caller keeps ESI | **High** |
| Vec1 +0x72c / +0x730 | imm `2c 07` / `30 07` | **High** |
| Vec2 +0x73c / +0x740 | imm `3c 07` / `40 07` | **High** |
| Count `(end-begin)>>2` | `sub` / `sar …,2` | **High** |
| Child vtbl+0x440 | `ff 92 40 04 00 00` | **High** |
| Dialog vtbl+0xb0(child) | `push child; mov ecx,esi; call [edx+0xb0]` | **High** |
| Bare ret; saves EBX/EBP/EDI | `53 55 57` … `5f 5d 5b c3` | **High** |
| Body 207 B | exclusive end `008aa3ef` | **High** |
| Sole caller Flush @ `008ab998` | xrefs + assembly context | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null begin → count 0 | **Yes** |
| Loop both vectors | **Yes** |
| Skip null slots | **Yes** |
| Child 0x440 then dialog 0xb0 | **Yes** |
| No vector clear / no +0x650 | **Yes** |
| ESI ABI not ECX-thiscall | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF algorithm | **High** | sealed three-rep |
| ESI dialog ABI | **High** | sole caller preserves ESI |
| Role = child-list teardown on flush path | **High** | Flush plate + call order |
| Product list English (what widgets) | **Low–Med** | dynamic UI lists inferred |
| vtbl method product names | Open | structural destroy/remove |
| Runtime / bit-exact | Open | static dual only |

**Verdict:** **accept** — teardown CF + ABI + offsets sealed; product English residual.
