# Review A (reconstruction fidelity): `aa_00439810` stoChunkWriter_WriteU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439810` |
| **VA** | `0x00439810` |
| **Body** | `0x00439810`–`0x00439861` |
| **Canonical name** | `stoChunkWriter_WriteU32` |
| **System** | storage / arda2.stoChunk |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) — OWN-ONLY W20-D |
| **Counterpart** | `reviews/B_aa_00439810_stoChunkWriter_WriteU32.md` |
| **Tools** | Ghidra `decompile_function`, `read_memory` (own VA + `"%u"` / `"\r\n"` DATs); `get_function_xrefs` + `get_assembly_context` for ABI; no `disassemble_bytes`; no Launcher |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x00439810` |
| Body bytes | `read_memory` @ `0x00439810` len 96 (through dual `ret` + `cc` pad) |
| Format DAT | `0x00a9d718` → `"%u"` |
| CRLF DAT | `0x00a97b84` → `"\r\n"` |
| Sibling | `0x00439870` + `0x00a37c64` → `"%i"` (WriteI32 twin, dual-sealed W19-Q) |
| Formatted helper | `stoChunkWriter_WriteFormatted` @ `0x00767160` |
| Mode layout duals | Begin/EndChunk (`+0x1c` mode, `+0x20` textCol) |
| Call-site ABI | `get_assembly_context` on xrefs (ESI writer, EAX value*) |
| Raw / annotated / clean / record | semantic names under `aa_00439810_stoChunkWriter_WriteU32*` |

Three-rep **present and sealed this pass**.

---

## 2. Purpose (from unit)

Serialize one **unsigned int32** onto a chunk writer stream: raw LE dword when binary, or a text line `"%u\r\n"` when text.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Mode gate `ESI+0x1c == 0` → binary 4-byte write | **High** | body + Begin/EndChunk layout |
| Binary write size **4** | **High** | `push 4` / decompile |
| Text format `"%u"` @ `a9d718` | **High** | `read_memory` hex `25 75 00` |
| Text path calls `WriteFormatted` then zeros `+0x20` then writes CRLF | **High** | body order |
| Return = `status` OR at `+0x04` | **High** | both paths |
| ESI = writer, EAX = `uint32_t*` | **High** | call sites `lea eax,[…]; call` with ESI live |
| Name distinguishes unsigned (`%u`) from sibling `%i` | **High** | twin at `0x00439870` |
| Clean CF ≡ raw ≡ live | **High** | sealed |
| Runtime / golden text dump | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| `local = *EAX` | **Yes** |
| `if mode==0` binary write 4 | **Yes** |
| `status \|= result; return status` | **Yes** |
| else `WriteFormatted("%u", local)` | **Yes** |
| `textCol = 0` | **Yes** |
| write `"\r\n", 2` | **Yes** |
| `status \|= ; return status` | **Yes** |

---

## 5. Assembly-sealed body (from `read_memory`, no disassemble_bytes)

```
00439810  push ecx
00439811  cmp  dword [esi+0x1c], 0
00439815  mov  eax, [eax]          ; *pValue
00439817  jnz  text_path
; binary:
          mov  ecx, [esi]
          mov  [esp], eax          ; spill value
          mov  edx, [ecx]
          push 4
          lea  eax, [esp+4]
          push eax
          call [edx+0x18]
          or   [esi+4], eax
          mov  eax, [esi+4]
          pop  ecx
          ret
; text:
          push eax                 ; value arg
          push DAT_00a9d718        ; "%u"
          mov  eax, esi            ; writer → EAX for WriteFormatted
          call FUN_00767160
          mov  ecx, [esi]
          or   [esi+4], eax
          add  esp, 8
          push 2
          mov  dword [esi+0x20], 0
          mov  edx, [ecx]
          push DAT_00a97b84        ; "\r\n"
          call [edx+0x18]
          or   [esi+4], eax
          mov  eax, [esi+4]
          pop  ecx
          ret
```

---

## 6. Gaps

1. Stream interface class behind `*writer` not fully typed here.
2. No runtime capture of text vs binary output for a known value.
3. Prior alias `Named_CalleeOf_Named_effEffect_00439810` is xref noise — superseded by role name.

**Verdict:** **accept**
