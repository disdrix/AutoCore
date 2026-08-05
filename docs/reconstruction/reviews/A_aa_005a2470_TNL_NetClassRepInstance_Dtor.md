# Review A (reconstruction fidelity): `aa_005a2470` TNL_NetClassRepInstance_Dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2470` |
| **VA** | `0x005a2470`–`0x005a248e` exclusive |
| **Body size** | **30** B |
| **Canonical name** | `TNL_NetClassRepInstance_Dtor` |
| **Ghidra name** | `FUN_005a2470` |
| **Review date** | `2026-07-29` (W26-R dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_005a2470_TNL_NetClassRepInstance_Dtor.md` |
| **System** | `tnl` / NetClassRep |
| **Live tools** | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

In-place **TNL NetClassRepInstance ClassRep destructor**: free strdup'd class name at `+0x20`, restore base ClassRep vtbl. Complements sealed ctor `TNL_NetClassRepInstance_Ctor` (`FUN_005a2410`). Used by atexit thunk for static GuaranteedOrdered ClassRep and by scalar deleting dtor wrapper.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005a2470_FUN_005a2470.md` (+ 2026-07-29 W26-R append) |
| Annotated | `docs/reconstruction/raw/aa_005a2470_FUN_005a2470.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TNL_NetClassRepInstance_Dtor.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_005a2470.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a2470_TNL_NetClassRepInstance_Dtor.md` |
| Live decompile | Ghidra @ `0x005a2470` — **≡ raw** |
| Bytes | `read_memory` 64 B @ `0x005a2470` (full body + pad + next) |
| Callers | `FUN_009c3de0` (atexit dual W25-I), `FUN_005a2730` (scalar deleting) |
| Sibling | `A_aa_005a2410_TNL_NetClassRepInstance_Ctor` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Assembly-sealed body (`read_memory` @ `0x005a2470`)

Full body (30 B through `ret`):

```
56                   push esi
8b f1                mov  esi, ecx
8b 46 20             mov  eax, [esi+0x20]
50                   push eax
c7 06 f4 7b 9d 00    mov  dword [esi], 0x009d7bf4
ff 15 24 65 9c 00    call [0x009c6524]        ; free
83 c4 04             add  esp, 4
c7 06 f4 7a 9d 00    mov  dword [esi], 0x009d7af4
5e                   pop  esi
c3                   ret
```

Hex:
```
568bf18b462050c706f47b9d00ff1524659c0083c404c706f47a9d005ec3
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **30 bytes** through plain `ret` | hex + `CC` pad; next @ `005a2490` | **Confirmed** |
| `__thiscall` ECX=this | `mov esi,ecx` | **Confirmed** |
| Free name at `+0x20` | `mov eax,[esi+20]; push; free; add esp,4` | **Confirmed** |
| Derived vtbl during free `009d7bf4` | `C7 06 F4 7B 9D 00` same as ctor | **Confirmed** |
| Restore base vtbl `009d7af4` | `C7 06 F4 7A 9D 00` | **Confirmed** |
| No `operator_delete` / no ClassList walk | full body has neither | **Confirmed** |
| Live decompile ≡ bytes (order of free vs vtbl) | name pushed before free; vtbls as decompile | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Snapshot name | **Yes** |
| Install NetClassRepInstance vtbl | **Yes** |
| free(name) cdecl | **Yes** |
| Restore base vtbl | **Yes** |
| plain `ret` | **Yes** |
| No ClassList unlink | **Yes** (absent) |

---

## 5. Callers / product identity (High)

| Caller | Shape |
|---|---|
| `FUN_009c3de0` | `mov ecx, 0x00b04f40; jmp FUN_005a2470` — atexit for GuaranteedOrdered ClassRep (W25-I dual) |
| `FUN_005a2730` | call this; if `(flags & 1) operator_delete(this)` — scalar deleting dtor |

Sibling ctor dual sealed: same vtbl `009d7bf4`, name slot `+0x20`, ClassList prepend. Dtor frees what ctor strdup'd.

---

## 6. Gaps

1. Whether any non-static ClassRep path requires ClassList unlink (not this body).  
2. Sibling ClassRep dtor variants (e.g. `FUN_005a2630`) — separate VAs.  
3. Runtime free / process-exit observation — open / not required for CF seal.

**Verdict:** **accept**
