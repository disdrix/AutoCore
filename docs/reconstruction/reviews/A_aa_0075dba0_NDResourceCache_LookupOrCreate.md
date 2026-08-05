# Review A (reconstruction fidelity): `aa_0075dba0` NDResourceCache_LookupOrCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075dba0` |
| **VA** | `0x0075dba0` |
| **Canonical name** | `NDResourceCache_LookupOrCreate` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Rep A fidelity) |
| **Counterpart** | `reviews/B_aa_0075dba0_NDResourceCache_LookupOrCreate.md` |
| **System** | `nd-resource` / global resource name+type cache |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callees/xrefs (no `disassemble_bytes`) |
| **Body range** | `0x0075dba0`–`0x0075de54` |
| **Verdict** | **accept-with-gaps** (CF/ABI High; factory-list layout + secondary `+0x6c` path residual) |

---

## 1. Purpose

**Global resource cache keyed by name object + type token.** On a matching map entry, return the existing resource pointer (optionally gated by a predicate object). On miss (or failed type/predicate match), try optional alternate load path when `cache+0x6c` is set, then walk a factory registry; if still empty and `param5 != 1`, allocate a default **`0x3c`**-byte resource (`operator_new` + `FUN_00745d70` + vtbl `PTR_FUN_00a9e850`). Returns the resource pointer or **NULL**.

Primary observed wrapper: `NDResource_LoadByKey` (`0x00423ac0`) → `LookupOrCreate(*DAT_00d1f050, key, type, p3, p4)` then virtual `+0x04` init. Other xrefs pass the same global cache and similar 5-arg pattern.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075dba0_FUN_0075dba0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075dba0_FUN_0075dba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0075dba0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0075dba0_FUN_0075dba0.md` |
| Caller context (not owned) | `NDResource_LoadByKey` @ `0x00423ac0`; `FUN_00445080`; `FUN_0074ee40` |
| Callees (context) | map find `FUN_0044e8c0`; insert helpers; default ctor `FUN_00745d70`; factory list `FUN_0043c5f0` / dtor `FUN_0040d9c0` |

---

## 3. Seal: ABI + prologue (`read_memory` @ `0x0075dba0`)

### Prologue (entry)

```
64 a1 00 00 00 00       mov  eax, fs:[0]
6a ff                   push -1
68 68 fe 9a 00          push LAB_009afe68
50                      push eax
64 89 25 00 00 00 00    mov  fs:[0], esp
83 ec 3c                sub  esp, 0x3c
53 55 56                push ebx / ebp / esi
8b 74 24 58             mov  esi, [esp+0x58]   ; arg1 = cache
8b 46 6c                mov  eax, [esi+0x6c]
85 c0 57                test eax,eax ; push edi
74 06                   jz   skip_log_enter
50 e8 …                 push eax ; call FUN_00971480
8b 6c 24 60             mov  ebp, [esp+0x60]   ; arg2 = key
…
e8 …                    call FUN_0044e8c0      ; map lookup by key
```

### Epilogue (shared return paths)

```
… restore ExceptionList …
5f 5e 5d                pop edi / esi / ebp
64 89 0d 00 00 00 00    mov fs:[0], ecx
5b                      pop ebx
83 c4 48                add esp, 0x48
c2 14 00                ret 0x14               ; __stdcall, 5 × 4-byte args
```

Body ends at `0x0075de54` (`ret 0x14`); trailing `CC` padding.

### ABI table

| Item | Machine | Conf |
|---|---|---|
| Convention | **`__stdcall`**, **5** stack formals, **`ret 0x14`** | **High** |
| `param1` | `NDResourceCache* cache` (ESI); fields `+0x08` end sentinel, `+0x6c` optional path flag | **High** (role) |
| `param2` | Key / name object pointer (EBP); `*key` fed into insert/ctor | **High** (role) |
| `param3` | Type token (pointer or id); compared to **resource+0x0c** | **High** |
| `param4` | Optional predicate object; **vtbl+0x08** → bool in AL; **NULL** allowed | **High** (call site); semantic name **Probable** |
| `param5` | Create policy: **`== 1`** → no default `operator_new`; else allocate | **High** |
| Return | EAX = resource `undefined4*` or **NULL** | **High** |
| SEH | Standard MSVC frame + `LAB_009afe68` | **High** |

---

## 4. Control flow (machine ≡ decompiler)

```
SEH install
if (cache[+0x6c] != 0):
  FUN_00971480(cache[+0x6c])              // optional enter/log

FUN_0044e8c0(out_it)                      // hash/map find by key (uses cache as container)

if (it == cache[+0x08]):                  // miss / end sentinel
  // insert scaffolding: FUN_0043c6f0 + FUN_0043ba40
  // it advanced to value slot (node + 0x0C / +3 dwords)
else:
  res = *(it + 0x0C value)                // existing resource*
  it += 0x0C
  if (res != NULL && res[+0x0C] == type):
    if (res[+0x14] == 0):
      return res                          // hit; param4 ignored (both decompiler branches)
    else if (param4 != NULL):
      if (param4->vtbl[+0x08]() != 0):
        return res                        // predicate accept
  // else fall through (type miss or predicate reject / missing predicate)

// --- create / factory path ---
if (cache[+0x6c] != 0):
  alt = FUN_00970c00(key, type)           // alternate provider
  if (alt != NULL):
    *slot = alt; return alt
  FUN_00970b60()                          // miss side-effect / log

// factory registry list (temps; cleaned by FUN_0040d9c0)
zero list locals; FUN_0043c5f0(cache+0x28 region, list)
for each factory entry in list:
  res = factory->vtbl[+0x04](key, type)   // create/load attempt
  if (res != NULL):
    *slot = res
    if (cache[+0x6c] != 0):
      FUN_0043e8f0 / FUN_0043e7f0 / FUN_0043e630   // optional string/log chain
    FUN_0040d9c0(); return res

// factories exhausted
if (param5 != 1):
  res = operator_new(0x3c)
  if (res):
    FUN_00745d70(res, key, …)             // default resource ctor
    *res = &PTR_FUN_00a9e850              // install resource vtbl
  *slot = res
  FUN_0040d9c0(); return res
else:
  FUN_0040d9c0(); return NULL
```

### Hit-path type/predicate seal (`read_memory` @ ~`0x0075dc04`)

```
8b 4c 24 64    mov ecx, [esp+…]     ; type (param3)
39 4b 0c       cmp [ebx+0x0c], ecx  ; res+0x0c == type
0f 85 …        jne fallthrough
8b 43 14       mov eax, [ebx+0x14]  ; res+0x14
3b c2          cmp eax, edx         ; edx==0
75 1c          jne need_predicate
…              ; both param4 null/non-null → hit return when +0x14==0
…
8b 17          mov edx, [edi]       ; param4 vtbl
ff 52 08       call [edx+8]         ; predicate
84 c0 74 …     test al; jz fallthrough
…              ret res (stdcall epilogue)
```

### Default-create seal (`read_memory` @ ~`0x0075ddd8`)

```
83 7c 24 6c 01    cmp dword [esp+…], 1   ; param5
75 20             jne do_new
…                 FUN_0040d9c0; xor eax,eax; ret 0x14
6a 3c             push 0x3c
…                 operator_new → FUN_00745d70 → *obj = PTR_FUN_00a9e850
```

---

## 5. Resource / cache fields used **in this unit**

| Offset | Object | Use here | Conf |
|---|---|---|---|
| `cache+0x08` | map end / empty sentinel | miss if iterator equals | **High** |
| `cache+0x14..+0x24` | hash buckets (via `FUN_0044e8c0`) | find by key | **Probable** (callee) |
| `cache+0x28` | factory-list source | `FUN_0043c5f0` fill | **Probable** |
| `cache+0x6c` | optional secondary path / logging | gate `00971480` / `00970c00` / log trio | **High** (gate); meaning **Open** |
| `res+0x00` | vtbl | not called here (callers use +4) | — |
| `res+0x0c` | type token | equality vs `param3` | **High** |
| `res+0x14` | optional attached object / cookie | `0` ⇒ unconditional hit; nonzero ⇒ need predicate | **High** (behavior); type **Open** |
| map node `+0x0c` | value slot | stores resource* | **High** |

Default ctor context (`FUN_00745d70`, not owned): zeros `+0x14` unless a non-null ctor arg runs **vtbl+4** into `+0x14`. That explains why freshly allocated defaults always take the unconditional-hit arm.

---

## 6. Call graph (own edges)

| Dir | Target | Role |
|---|---|---|
| Calls | `FUN_00971480` | optional enter when `cache+0x6c` |
| Calls | `FUN_0044e8c0` | map/hash find by key |
| Calls | `FUN_0043c6f0` / `FUN_0043ba40` | miss-path insert scaffolding |
| Calls | `FUN_00970c00` / `FUN_00970b60` | alternate lookup / side-effect when `+0x6c` |
| Calls | `FUN_0043c5f0` / `FUN_0040d9c0` | factory list build / destroy |
| Calls | factory **vtbl+0x04** (indirect) | create attempt |
| Calls | `operator_new(0x3c)` + `FUN_00745d70` | default resource |
| Calls | `FUN_0043e8f0` / `0043e7f0` / `0043e630` | optional log/string when factory hit + `+0x6c` |
| Calls | predicate **vtbl+0x08** (indirect) | hit accept when `res+0x14 != 0` |
| Called by | ≥13 sites (`NDResource_LoadByKey`, `FUN_00445080`, XML/asset loaders, …) | same global `DAT_00d1f050` pattern on several |

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 5-arg stdcall, `ret 0x14` | **High** | epilogue bytes |
| Returns resource* or NULL | **High** | all return sites |
| Map find then type match at `+0x0c` | **High** | machine |
| `res+0x14==0` → return hit ignoring param4 | **High** | twin branches same exit |
| `res+0x14!=0` → need param4 and vtbl+8 true | **High** | machine |
| `param5==1` suppresses default `new(0x3c)` | **High** | `cmp …,1` then null return |
| Default object size `0x3c`, vtbl `PTR_FUN_00a9e850` | **High** | push 0x3c + store |
| Name `NDResourceCache_LookupOrCreate` | **High** | Ghidra plate + wrapper dual |
| Exact C++ type of key / type token | **Tentative** | opaque objects |
| Meaning of `cache+0x6c` payload | **Open** | only non-zero gate sealed |
| Factory list element layout | **Open** | index math residual (`>>2`, wrap) |
| Bit-exact / runtime | **Open** | not run |

---

## 8. Control flow: clean ≡ raw ≡ machine

| Stage | Match after seal |
|---|---|
| SEH + optional `+0x6c` enter | **Yes** |
| Map find; miss insert vs hit type check | **Yes** |
| Predicate gate on `+0x14` | **Yes** |
| Alternate `00970c00` then factory loop | **Yes** |
| `param5==1` → null else `new(0x3c)` default | **Yes** |
| stdcall 5 args | **Yes** (scaffold three-rep lacked explicit `ret 0x14` note; CF body matches) |

Three-rep is **scaffold-grade** (auto CF preserve) but **behavior-aligned** with live decompile. Dual does not require a full three-rep rewrite for seal.

---

## 9. Gaps / open

1. Precise type of map key object and type token (pointer-to-singleton vs integer id — wrappers pass singleton addresses like `&DAT_00d1f734`).
2. Full semantics of `cache+0x6c` (debug logger object? secondary store?).
3. Factory registry layout and which concrete factories register (not owned).
4. Whether `param4` is always a match-predicate interface or sometimes a create-context (ctor of default path can take a related arg via other call sites — not sealed here).
5. Runtime / bit-exact harness not run.

**Verdict:** **accept-with-gaps**
