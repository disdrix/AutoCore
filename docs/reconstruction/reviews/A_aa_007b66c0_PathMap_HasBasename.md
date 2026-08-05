# Review A (reconstruction fidelity): `aa_007b66c0` PathMap_HasBasename

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b66c0` |
| **VA** | `0x007b66c0`–`0x007b6728` |
| **Canonical name** | `FUN_007b66c0` (descriptive INFERRED: PathMap_HasBasename) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual A / W17-M) |
| **Counterpart** | `reviews/B_aa_007b66c0_PathMap_HasBasename.md` |
| **System** | ND path / interface resource map |
| **Verdict** | **accept** — body + ABI sealed |

---

## 1. Purpose

Flag-gated **path basename token lookup**. When `*(ctx+4) & 2` is set, take the last path component of the EAX C-string (after the later of `\` / `/`), intern it through the global string pool (`FUN_00989e00` @ `this=0x00d1eac8`), and query `*(ctx+0xc)->vtbl+0x14`. Return **1** if the virtual call is non-zero, else **0**.

Used by interface/XML path loaders (e.g. `NDUIWindow_LoadInterfaceFile`) when deciding whether a path basename is known to a resource map after locale filesystem probes fail.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b66c0_FUN_007b66c0.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_007b66c0_FUN_007b66c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007b66c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b66c0_FUN_007b66c0.md` |
| Live Ghidra | `decompile_function` + `force_decompile` `0x007b66c0` (identical) |
| | `read_memory` 104 B body; IAT dword @ `0x009c662c` |
| | `get_function_by_address` body `007b66c0`–`007b6728` |
| | callees / callers / xrefs |
| Tools avoided | `disassemble_bytes` (policy) |

**Dual A/B decompile agreement:**

```
undefined4 FUN_007b66c0(int param_1) {
  ... identical body in both reps ...
  return 0 or 1;
}
```

No third-rep required.

---

## 3. Signature

```c
// path in EAX; one stack arg; RET 4; AL bool
uint8_t FUN_007b66c0(void *ctx, /* EAX */ const char *path);
```

| Item | Evidence |
|---|---|
| Path register | `MOV EDI,EAX` before strrchr uses |
| Stack ctx | `MOV EBP,[ESP+8]` after push ebp |
| Callee clean | `C2 04 00` both return paths |
| Bool return | `MOV AL,1` / `XOR AL,AL` |

---

## 4. Control flow (sealed)

```
if ((*(u8*)(ctx+4) & 2) == 0) return 0;
b = strrchr(path,'\\'); f = strrchr(path,'/');
basename = (no seps) ? path : max(b,f)+1;
FUN_00989e00(pool=0x00d1eac8, &token, basename);
hit = (*(ctx+0xc))->vtbl+0x14(&token);
return hit ? 1 : 0;
```

---

## 5. Machine bytes

104 B hex recorded in raw append. Key immediates: `PUSH 0x5C`, `PUSH 0x2F`, `MOV ECX,0x00d1eac8`, `CALL FUN_00989e00`, `CALL [EDX+0x14]`.

---

## 6. Gaps (non-blocking)

1. Product type name of `ctx` / map at `+0xc`.
2. Product meaning of flag bit value **2**.
3. Exact token type from `FUN_00989e00`.
4. Runtime path hit/miss observation.

---

## 7. Verdict rationale

Decompile×2 ≡ raw scaffold control flow; bytes confirm ABI, gate mask, separators, pool address, virtual offset, and 0/1 returns. Safe to **accept** body seal without inventing a retail symbol name.
