# Review A (reconstruction fidelity): `aa_00436190` FourCC_DwordToStdString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436190` |
| **VA** | `0x00436190` |
| **Body span** | `00436190` – `0043621f` |
| **Canonical name** | `FourCC_DwordToStdString` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory` of body) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_00436190_FourCC_DwordToStdString.md` |
| **System** | `util` / fourcc |
| **Dual status** | **Present** |
| **Verdict** | **accept** |

---

## 1. Purpose

Build a **big-endian FourCC C string** from a `uint32` tag and **copy-construct** it into a caller-owned `std::string`, returning the out pointer. Supports phy bounding-volume invalid-tag logging and sto chunk FourCC text paths.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00436190_FUN_00436190.md` |
| Annotated | `docs/reconstruction/raw/aa_00436190_FUN_00436190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00436190.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/FourCC_DwordToStdString.cpp` |
| Function record | `docs/reconstruction/functions/aa_00436190_FUN_00436190.md` |

**This pass (live, OWN VA only):**

- Ghidra MCP `decompile_function` @ `0x00436190` — matches raw plate body.
- Ghidra MCP `read_memory` @ `0x00436190` length 144 — body ends `83 C4 34 C3`; three import `FF 15` sites for string ctor/copy/dtor.
- `get_function_by_address` — body `00436190`–`0043621f`.
- `get_function_xrefs` — 3 callers (wrapper, `stoChunkWriter_BeginChunk`, phy BV factory).
- **Not performed:** Launcher, runtime golden, bit-exact binary diff; no ownership of caller VAs.

---

## 3. Calling convention (assembly-sealed on OWN body)

| Slot | Role | Evidence |
|---|---|---|
| **[esp+…] arg0** | `std::string *out` | Loaded into `ESI`; returned in `EAX` |
| **[esp+…] arg1** | `uint32_t tag` | Loaded into `EAX`; byte-split into 5-byte buf |
| **Return** | `out` | `mov eax, esi` |
| **Cleanup** | `__cdecl` | `add esp, 0x34; ret` — **not** `ret 8` |

Ghidra signature returning `basic_string*` with two stack params is **behaviorally correct**.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `00436190`–`0043621f` | **High** | bounds + `read_memory` end `C3` |
| `__cdecl` | **High** | bare `ret` |
| BE layout `b0=>>24 … b3=&0xff; b4=0` | **High** | decompile + asm store order |
| Temp string → copy into out → dtor temp | **High** | three import calls + SEH state `local_4` |
| Tag `0` → empty string | **High** | first byte 0 |
| FourCC semantic name | **High** | callers + `0x42565350` etc. in factory |
| Clean ≡ raw CF | **High** | scaffold rewrite only |
| Bit-for-bit / runtime | **Open** | deferred |

---

## 5. Control flow checklist (clean ≡ raw ≡ live)

| Stage | Match |
|---|---|
| SEH frame install | **Yes** (omitted from clean as non-behavioral) |
| Extract 4 BE bytes + NUL | **Yes** |
| `string(tmp, buf)` | **Yes** |
| `string(out, tmp)` | **Yes** |
| `~string(tmp)` | **Yes** |
| Restore ExceptionList; return out | **Yes** |
| No invent branches / extra callees | **Yes** |

---

## 6. Gaps

1. MSVC `std::string` ABI / SSO details left to CRT (not reimplemented).
2. Mid-string zero high-bytes would truncate C-string ctor — only relevant for non-ASCII tags.
3. Runtime / differential verification **Open**.

**Verdict:** **accept** — CF and BE FourCC contract sealed High for AutoCore ports; safe to use for tag formatting and invalid-tag messages.
