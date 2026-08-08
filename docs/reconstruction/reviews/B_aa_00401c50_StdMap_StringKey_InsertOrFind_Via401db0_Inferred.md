# Review B (skeptical / adversarial): `aa_00401c50` StdMap_StringKey_InsertOrFind_Via401db0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401c50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-064) |
| **Counterpart** | `reviews/A_aa_00401c50_StdMap_StringKey_InsertOrFind_Via401db0_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Scaffold `Named_CalleeOf_*Mission_Attempting_to_open_null_dialog*` is product name | **Falsified** — chain-of-caller plate only; host string @ `0x00a84654` is ancestor evidence, not this unit's demangle |
| 2 | This **is** Mission dialog product method English | **Narrowed** — sole caller under that path; no PDB/demangle for map type |
| 3 | Same symbol as twin `0x004309c0` / merge clean bodies | **Falsified** — identical CF/ABI/isnil family but insert workers differ (`00401db0` vs `00430b60`); monomorph twins, do not merge |
| 4 | isnil31 / isnil29 family | **Falsified** — all guards isnil@**+0x2d** |
| 5 | Freelist / CNDHash / char-key map (`00402210`) | **Falsified** — string IAT `<` + tree lower-bound + pred + insert hint |
| 6 | Always inserts (no equal path) | **Falsified** — inserted=0 path sealed at `00401d16`–`00401d24` |
| 7 | Successor / erase / lower_bound-only (no insert) | **Falsified** — two insert call sites + found path |
| 8 | Decompiler `void` / single `int param_1` is true ABI | **Falsified** — stack map + EAX key + EBX out; returns out*; **RET 4** |
| 9 | Decompiler `std::operator<<` is stream insert | **Falsified** — IAT slot is string **`operator<`** (mangling display artifact) |
| 10 | thiscall ECX=map | **Falsified** — map is stack arg; ECX only set when calling insert worker as where |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| String key compare + offsets | **High** | wrong key layout / port bug |
| isnil@+0x2d | **High** | wrong family merge |
| Stack/EAX/EBX RET 4 ABI | **High** | call-site misuse |
| Insert worker linkage | **Med** | undualed residual |
| Product English | Medium | naming only |
| Mapped value layout after string | Low–Med | port value type |

---

## 3. Cross-check against raw + bytes

```
sub esp,8
mov edx,[esp+0xc]        ; map*
mov ebp,[edx+4]          ; head
mov esi,[ebp+4]          ; root
cmp byte ptr [esi+0x2d],0
mov edi,eax              ; key*
... walk: call [009c62e8] operator< (key, node+0xc); L/R ...
optional: call 004313d0  ; pred EDX
if equal: [ebx]=where; [ebx+4]=0; mov eax,ebx; ret 4
else: call 00401db0      ; insert; [ebx]=new; [ebx+4]=1; mov eax,ebx; ret 4
```

Clean must keep **stack map / EAX key / EBX out**, isnil2D string key, and not invent Mission product method names or merge with `004309c0`.

---

## 4. Surviving contract for AutoCore

```csharp
// Unique insert-or-find string key (isnil2D), stack map + EAX key + EBX out, RET 4
InsertPair InsertOrFind_StringKey(Map map /*stack*/, string key /*EAX*/, InsertPair out /*EBX*/)
{
    // lower_bound walk via operator<; optional predecessor; equal → inserted=false
    // else InsertHint_Via401db0(map, where, addLeft, key) → inserted=true
    return out;
}
```

Port must not merge with monomorph twin `004309c0` (different insert worker) or claim Mission dialog product without demangle.

---

## 5. Open questions

1. English mapped type under Mission null-dialog host.  
2. Dual of `FUN_00401db0` insert worker.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
