# Review A (reconstruction fidelity): `aa_00423ac0` NDResource_LoadByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423ac0` |
| **VA** | `0x00423ac0` |
| **Canonical name** | `NDResource_LoadByKey` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00423ac0_NDResource_LoadByKey.md` |
| **System** | `nd-resource` / MSXML asset cache |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callees/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** (CF/ABI High; param3/param4 + vtbl+4 semantics residual) |

---

## 1. Purpose

Thin **stdcall** wrapper: resolve (or create) a cache entry by key under the global `NDResourceCache` at `DAT_00d1f050`, store the object pointer through an out-parameter, then invoke **virtual +0x04** (init/load) on the resource. Returns a **tristate int**: **−1** null, **0** init false, **1** init true.

Primary observed caller: `NDXml_LoadDocumentFromPath` (`0x007b6c70`) with `(pOut, key, 0, 0)`. That caller treats only **`< 0`** as hard failure; init-fail (**0**) still takes the success-side path (AcquireInnerObject / Release).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00423ac0_NDResource_LoadByKey.md` |
| Annotated | `docs/reconstruction/raw/aa_00423ac0_NDResource_LoadByKey.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResource_LoadByKey.cpp` |
| Function record | `docs/reconstruction/functions/aa_00423ac0_NDResource_LoadByKey.md` |
| Callees (context, not owned) | `FUN_00423b10` @ `0x00423b10`; `NDResourceCache_LookupOrCreate` @ `0x0075dba0` |
| Caller (context) | `NDXml_LoadDocumentFromPath` @ `0x007b6c70` (only code xref) |

---

## 3. Seal: body (`read_memory` @ `0x00423ac0`)

Body range **`0x00423ac0`–`0x00423b0a`** (`ret 0x10`); padding `CC` after. Hex:

```
56 e8 4a 00 00 00 8b 4c 24 14 8b 54 24 10 51 8b 0d 50 f0 d1 00
52 50 8b 44 24 18 50 51 33 f6 e8 bc a0 33 00 85 c0 8b 54 24 08
89 02 75 07 83 c8 ff 5e c2 10 00 8b 10 8b c8 ff 52 04 84 c0 74 05
be 01 00 00 00 8b c6 5e c2 10 00 cc cc cc cc cc
```

### Control flow (machine)

```
push esi
call FUN_00423b10                    ; EAX = type token (&DAT_00d1f734 singleton)
mov  ecx, [esp+0x14]                 ; param4
mov  edx, [esp+0x10]                 ; param3
push ecx                             ; arg5 = param4
mov  ecx, [0x00d1f050]               ; g_pNDResourceCache (DAT_00d1f050)
push edx                             ; arg4 = param3
push eax                             ; arg3 = type token
mov  eax, [esp+0x18]                 ; param2 key (after 3 pushes)
push eax                             ; arg2 = key
push ecx                             ; arg1 = cache
xor  esi, esi                        ; success accumulator = 0
call NDResourceCache_LookupOrCreate  ; @ 0x0075dba0
test eax, eax
mov  edx, [esp+0x8]                  ; pOut
mov  [edx], eax                      ; *pOut = resource (even if null)
jnz  do_init
  or   eax, -1                       ; return 0xFFFFFFFF
  pop  esi
  ret  0x10

do_init:
mov  edx, [eax]                      ; vtable
mov  ecx, eax                        ; this = resource
call dword ptr [edx+4]               ; virtual +0x04 (thiscall)
test al, al
jz   ret_esi                         ; keep ESI=0 → return 0
mov  esi, 1
ret_esi:
mov  eax, esi
pop  esi
ret  0x10
```

### ABI

| Item | Machine | Conf |
|---|---|---|
| Convention | **`__stdcall`**, **4** stack formals, **`ret 0x10`** | **High** |
| `param1` | `void** pOutResource` (always written, including null) | **High** |
| `param2` | key / name object (caller builds path string object) | **High** (role); type layout **Probable** |
| `param3` | opaque; NDXml passes **0** | **Tentative** (forwarded to LookupOrCreate) |
| `param4` | opaque; NDXml passes **0** | **Tentative** (forwarded; cache may treat as create policy) |
| Return | EAX: **−1** null, **0** init false, **1** init true (via ESI) | **High** |
| ESI | Clobbered as success flag; restored before return | **High** |

### Globals / callees (this unit)

| VA / symbol | Role here |
|---|---|
| `DAT_00d1f050` (`0x00d1f050`) | Pointer load → first arg to `NDResourceCache_LookupOrCreate` (global cache) |
| `FUN_00423b10` | One-shot init of type singleton `DAT_00d1f734` (`PTR_FUN_00a95ae8`); returns `&DAT_00d1f734` as **type token** |
| `NDResourceCache_LookupOrCreate` @ `0x0075dba0` | Cache lookup/create; 5-arg call from this wrapper |
| Virtual `[*resource + 4]` | Init/load; return **bool** in AL → mapped to 0/1 |

Static image bytes at `0x00d1f050` are zero in the PE dump (BSS / runtime-filled); only the **load site** is sealed here.

### Call graph (own edge)

| Dir | Target | Notes |
|---|---|---|
| Calls | `FUN_00423b10` | type token |
| Calls | `NDResourceCache_LookupOrCreate` | cache |
| Calls | indirect vtbl+4 | resource init |
| Called by | `NDXml_LoadDocumentFromPath` only (Ghidra code xref) | `LoadByKey(&local_28, local_30, 0, 0)` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 4-arg stdcall, `ret 0x10` | **High** | machine |
| Always writes `*pOut` before null check | **High** | `mov [edx],eax` then `jnz` |
| Null → return **−1** (no virtual call) | **High** | `or eax,-1` |
| Non-null → vtbl **+4** thiscall | **High** | `mov ecx,eax; call [edx+4]` |
| Init AL false → **0**, true → **1** | **High** | ESI 0/1 |
| Type arg is `FUN_00423b10()` singleton, not a formal | **High** | inserted between key and param3 |
| Cache object is `*[DAT_00d1f050]` | **High** | `mov ecx,[0x00d1f050]` |
| NDXml treats only `<0` as error (0 still “ok” branch) | **High** | caller decompile (context) |
| Human name of vtbl+4 (Load / Init / Open) | **Probable** | plate says init/load |
| Semantic names for param3/param4 | **Open** | only 0/0 observed at sole xref |
| Full cache create/policy when param4==1 | **Open** | owned by LookupOrCreate |

---

## 5. Control flow: clean ≡ raw ≡ machine

| Stage | Match after seal |
|---|---|
| type token ← `FUN_00423b10` | **Yes** |
| LookupOrCreate(cache, key, type, p3, p4) | **Yes** |
| `*pOut = result` | **Yes** |
| null → −1 | **Yes** |
| vtbl+4 → 0/1 | **Yes** |
| stdcall 4 args | **Yes** (clean refined) |

---

## 6. Gaps / open

1. Exact C++ types for `param2` key and `param3`/`param4` (predicate / create flags per cache body).
2. Resource vtable identity at `PTR_FUN_00a9e850` (default allocate path in cache) — not owned.
3. Whether other binary modules call this entry by absolute address without Ghidra code xref.
4. Runtime / bit-exact harness not run.

**Verdict:** **accept-with-gaps**
