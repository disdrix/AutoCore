# Review A (reconstruction fidelity): `aa_004e2f70` Dword_FillN_ReturnEnd_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2f70` |
| **VA** | `0x004e2f70` |
| **Canonical name** | `Dword_FillN_ReturnEnd_Inferred` |
| **Ghidra name** | `FUN_004e2f70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B, W16-B) |
| **Counterpart** | `reviews/B_aa_004e2f70_Dword_FillN_ReturnEnd_Inferred.md` |
| **System** | util / container (generic dword fill-n) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf **fill-n** for **4-byte** POD elements:

1. Write `*pValue` into each of `count` consecutive dwords starting at `dst`.
2. Return **end** pointer `dst + count` (asm: `lea eax,[dst+count*4]`).

**Not** memcpy / copy-n: the source pointer is **never advanced** — the same dword value is replicated. Used as a hole-fill helper inside MSVC-style `vector` insert/grow paths (scaffold seed: nested callee under `CVOGSectorMap_AddCharacter` chain; multi-caller generic).

ABI: free function, **three stack args**, **`ret 0x0C`**. ECX unused (not thiscall).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e2f70_FUN_004e2f70.md` (+ 2026-07-29 seal append) |
| Annotated | `docs/reconstruction/raw/aa_004e2f70_FUN_004e2f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Dword_FillN_ReturnEnd_Inferred.cpp` |
| Ghidra twin | `docs/reconstruction/reconstructed-exact/FUN_004e2f70.cpp` |
| Named scaffold | `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter_004e2f70.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e2f70_Dword_FillN_ReturnEnd_Inferred.md` |
| Live decompile | Ghidra MCP `decompile_function` @ `0x004e2f70` — **≡ raw** |
| Bytes | `read_memory` 64 B — fill loop, `lea [edi+esi*4]`, `C2 0C 00` |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`, live xref dump.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live decompile | **Confirmed** | CF spine identical |
| Three stack formals; **`ret 0x0C`** | **Confirmed** | `C2 0C 00` |
| Free helper (ECX unused) | **Confirmed** | no ECX load/store of `this` |
| Element stride **4** | **Confirmed** | `add eax,4` / `lea [edi+esi*4]` |
| Fill from `*pValue` without advancing `pValue` | **Confirmed** | loop reloads/`mov ebx,[edx]` from fixed edx |
| Return end = `dst + count` (pointer units) | **Confirmed** | decompile + `lea` |
| count==0 → return dst | **Confirmed** | `test esi; jbe` then same lea |
| No allocation / no free / no domain math | **Confirmed** | leaf |
| memcpy / copy range of distinct elements | **Falsified** | src fixed |
| Product demangled name (`fill_n` / etc.) | **Open** | structural INFERRED |
| Domain exclusivity (sector map only) | **Falsified** | multi-caller util (reconstructed insert parents) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load count / dst / pValue from stack | Yes |
| Early path count==0 | Yes |
| Loop store dword, advance dst by 4 | Yes |
| pValue not advanced | Yes |
| Return end pointer | Yes |
| ret 0x0C | Yes |

### Recovered CF

```c
// uint32_t *Dword_FillN_ReturnEnd(dst, count, pValue)
uint32_t *p = dst;
for (int n = count; n != 0; --n) {
  *p = *pValue;   // pValue fixed
  ++p;
}
return dst + count;
```

### Instruction seal (`read_memory` 2026-07-29)

```text
56                     push esi
8B 74 24 0C            mov esi, [esp+0x0C]   ; count
85 F6                  test esi, esi
57                     push edi
8B 7C 24 0C            mov edi, [esp+0x0C]   ; dst
8B C7                  mov eax, edi
76 14                  jbe done
8B 54 24 14            mov edx, [esp+0x14]   ; pValue
8B CE                  mov ecx, esi
53                     push ebx
/* loop */
8B 1A                  mov ebx, [edx]
89 18                  mov [eax], ebx
83 C0 04               add eax, 4
83 E9 01               sub ecx, 1
75 F4                  jnz loop
5B                     pop ebx
8D 04 B7               lea eax, [edi+esi*4]  ; end
5F 5E C2 0C 00         pop edi; pop esi; ret 0x0C
```

Body size **0x2C** bytes (to `ret 0x0C` inclusive).

---

## 5. Callers (context only)

| Role | Notes |
|---|---|
| Vector insert/grow hole fill | Reconstructed parents call `FUN_004e2f70(dst, n, &value)` then advance end |
| Scaffold seed | Nested under `CVOGSectorMap_AddCharacter` naming chain — **not** exclusive |
| Callees | **none** |

Full address inventory **Open** (OWN-ONLY no xref tool).

---

## 6. Gaps / open

1. Product / demangled CRT or STL helper name.
2. Exhaustive caller list / which element domains share the helper.
3. Runtime / bit-exact image diff.
4. Whether any caller passes a moving source (would be a misuse — body still reads fixed `*pValue`).

**Verdict:** **accept-with-gaps**
