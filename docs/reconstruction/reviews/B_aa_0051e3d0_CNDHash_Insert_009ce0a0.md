# Review B (skeptical / adversarial): `aa_0051e3d0` CNDHash_Insert_009ce0a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e3d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-D) |
| **Counterpart** | `reviews/A_aa_0051e3d0_CNDHash_Insert_009ce0a0.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Product name is `VOG_DEBUG_STOP` | Auto string-seed alias | **Falsified** as API name — diagnostic log only |
| 2 | Same unit as `CNDHash_Insert_009ce0a8` (`0x0051e4d0`) | Near-identical decomp | **Falsified** — different node vtbl imm (`009ce0a0` vs `009ce0a8`); separate VA |
| 3 | Same unit as `CNDHash_Insert` (`0x0053c560`) | Shared CF family | **Falsified** — different VA + vtbl `009cefd4` |
| 4 | Soft flag allows multi-value insert | Name `allowDuplicate` | **Falsified** — return 1 without mutation |
| 5 | Lock aborts insert | Error path assumption | **Falsified** — logs then continues |
| 6 | `__cdecl` / wrong stack cleanup | Ghidra void signature noise | **Falsified** — **`ret 0xC`** all exits |
| 7 | Returns node pointer | Common insert shape | **Falsified** — HRESULT-style int codes only |
| 8 | Freelist is global CRT | `operator_new` assumption | **Falsified** — `LEA ECX,[this+0x20]` + `FUN_0053ada0` |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert CF + return codes | **High** | Wrong port semantics |
| Node vtbl distinction | **High** | Wrong dtor / specialty merge |
| softIfExists = soft-skip | **High** | Silent multi-insert bug |
| Freelist at `+0x20` | **High** | Alloc on wrong object |
| Product specialty / value type | **Low–Med** | Naming only |
| `FUN_00519a30` domain | **Med** | Caller-context doc |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex via `read_memory` | **Yes** — starts `5333db…`, ends `…33c05bc20c00` |
| Vtbl imm `A0 E0 9C 00` | **Yes** |
| Strings HashError / VOG / Duplicate | **Yes** at sealed VAs |
| Twin 0051e4d0 dual | **Different vtbl / VA** |
| Caller soft=0 | **Yes** (3 sites) |

**Attack on “this is the medal insert (009ce0a8)”:** **Fails** — medal dual owns `0x0051e4d0` / vtbl `009ce0a8`; this unit stamps `009ce0a0`.

**Attack on “VOG_DEBUG_STOP product API”:** **Fails** — lock diagnostic only; body is generic CNDHash insert.

---

## 4. Surviving contract for AutoCore

```
// thiscall ret 0xC
// CNDHash_Insert_009ce0a0(hash, key, value, softIfExists) ->
//   0x80004003 if value==null
//   log if locked (continue)
//   if softIfExists && Lookup(key): return 1
//   if Lookup(key): log + return 0x80004005
//   node = freelist_alloc(hash+0x20); vtbl=009ce0a0; link bucket+list; count++; return 0
```

**Falsified port mistakes:**

- Merging with `0051e4d0` / `0053c560` call sites.
- Treating soft flag as multi-map insert.
- Aborting on traversal lock.
- Using CRT `new` instead of freelist at `+0x20`.

---

## 5. Open questions

1. Product specialty / value type for `009ce0a0` nodes at `FUN_00519a30`.
2. Freelist + integrity helper duals.
3. Runtime / bit-exact.

**Verdict:** **accept** — sealed CF/ABI/HRESULTs/vtbl; reject VOG-name and twin-identity myths.
