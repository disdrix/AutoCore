# Review B (skeptical / adversarial): `aa_00405bd0` StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405bd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9K-D) |
| **Counterpart** | `reviews/A_aa_00405bd0_StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Scaffold `Named_CalleeOf_*Error_Received_a_packet*` is product name | **Falsified** — chain-of-caller plate only |
| 2 | This **is** TFID map product method English | **Narrowed** — caller packs TFID fields; no demangle/PDB for map type |
| 3 | Same symbol as thiscall twin `0x004cbee0` | **Falsified** — different ABI (EBX/EAX/ESI bare RET vs thiscall RET8); do not merge |
| 4 | isnil31 / isnil21 family | **Falsified** — all guards isnil@+0x29 |
| 5 | Freelist / CNDHash insert | **Falsified** — classic tree lower-bound + pred + insert hint |
| 6 | Always inserts (no equal path) | **Falsified** — inserted=0 path sealed at `00405c71` |
| 7 | Successor / erase role | **Falsified** — predecessor only; insert-or-find CF |
| 8 | Decompiler `void` / no formals is true ABI | **Falsified** — register formals EBX/EAX/ESI; returns out* |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pair compare order | **High** | wrong key order / port bug |
| isnil@+0x29 | **High** | wrong family |
| Register ABI | **High** | call-site misuse |
| Insert worker linkage | **Med** | undualed residual |
| Product English | Medium | naming only |
| Mapped value layout beyond pair | Low–Med | port value type |

---

## 3. Cross-check against raw + bytes

```
sub esp,8
mov ecx,[ebx+4]          ; head
mov edi,eax              ; value*
... walk isnil@+0x29 with hi@+0x14 / lo@+0x10 ...
optional: call 00409820  ; pred EDX
if equal: [esi]=where; [esi+4]=0; ret
else: call 004069f0      ; insert; [esi]=new; [esi+4]=1; ret
```

Clean must keep **EBX map / EAX value / ESI out**, pair order, and not invent packet-error or TFID product method names.

---

## 4. Surviving contract for AutoCore

```csharp
// Unique insert-or-find pair key (isnil29), register ABI
InsertPair InsertOrFind_PairKey(Map map /*EBX*/, Val value /*EAX*/, InsertPair out /*ESI*/)
{
    // lower_bound walk; optional predecessor; equal → inserted=false
    // else InsertHint(map, where, addLeft, value) → inserted=true
    return out;
}
```

Port must not merge with thiscall twin `004cbee0` or claim TFID product without demangle.

---

## 5. Open questions

1. English pair / mapped type (TFID→timestamp blob?).
2. Dual of `FUN_004069f0` insert worker.
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
