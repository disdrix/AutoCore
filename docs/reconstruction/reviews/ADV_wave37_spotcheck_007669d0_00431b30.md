# ADV spot-check — W37-E `0x007669d0` + `0x00431b30`

| Field | Value |
|---|---|
| **Role** | Independent adversarial verifier (not OWN dual author) |
| **Date** | `2026-08-04` |
| **Partition** | W37-E (`WAVE_2026-08-04_wave37_partition_map.md`) |
| **Report under test** | `docs/agents/task-dual-ab-007669d0-00431b30-w37e-report.md` |
| **Units** | `0x007669d0` (`stoFileOSFile_Open`), `0x00431b30` (`StdVector_BuyN_BasicString`) |
| **Ghidra tools** | `batch_decompile` + `read_memory` + `get_function_callers` + `get_xrefs_to`. **No** `disassemble_bytes`. |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Evidence inspected

### Dual package (on disk)

| Kind | `0x007669d0` | `0x00431b30` |
|---|---|---|
| Dual report | W37-E agent report (both units) | same |
| Review A | `A_aa_007669d0_stoFileOSFile_Open.md` | `A_aa_00431b30_StdVector_BuyN_BasicString.md` |
| Review B | `B_aa_007669d0_stoFileOSFile_Open.md` | `B_aa_00431b30_StdVector_BuyN_BasicString.md` |
| Raw (+ W37-E append) | `raw/aa_007669d0_FUN_007669d0.md` | `raw/aa_00431b30_FUN_00431b30.md` |
| Annotated | present | present |
| Clean | `stoFileOSFile_Open.cpp` | `StdVector_BuyN_BasicString.cpp` |
| Twin | `FUN_007669d0.cpp` | `FUN_00431b30.cpp` |
| Function named | present | present |
| Scratch | `tmp/a_007669d0.md` | `tmp/a_00431b30.md` |

### Live Ghidra (this session)

1. **`batch_decompile`** `0x007669d0`, `0x00431b30`, nested throw `0x004540b0`.
2. **`read_memory`**
   - Open entry `0x007669d0` (64 B): `81 EC 04 02 00 00 … 89 41 04` (frame + mode@+4).
   - Open epilogue / jump table region `0x00766d80` (48 B): success `33 C0 … C2 0C 00`; fail path at `0x00766d6e` `83 C8 FF … C2 0C 00`; table @ `0x00766d90`.
   - Mode case bodies `0x00766cd0` (48 B): `0x20001` / case6 disposition `2` + access `0x20006` / case3 `0x20007` / CreateFile setup `push 1` share.
   - Buy full body `0x00431b30` (96 B incl. pad): 82 B live + `CC` pad; dual `C2 04 00`; max imm `49 92 24 09`; `B0 01` success.
   - Log path `0x00a9d944` → `C:\vog\1_code\palantir\arda2\storage\stoFileOSFile.cpp`.
   - Fail fmt `0x00a9d97c` → `File open error <%s> - %s`.
   - Quality tags `0x00a9d998` → `_DE\0_FR\0_UK\0.ogg`.
   - DDS ext `0x00a2c53c` → `.dds`.
   - Suffix pointer table `0x00b01838` (5×DWORD, loop end `0x00b0184c`): → `_on`, `_off`, `_over`, `_down`, **empty C-string**.
   - 5th entry target `0x00a1419b`: byte is `\0` (terminator after `…ode string`); empty suffix confirmed.
3. **Callers / xrefs**
   - Open: 10 named callers; 14 unconditional call xrefs (matches report).
   - Buy: sole caller `FUN_00469d10` @ `0x00469d56`.

---

## Unit A — `0x007669d0` stoFileOSFile_Open

### Confirmations (sealed claims hold)

| Claim | Independent result | Conf |
|---|---|---|
| Body `0x007669d0`–`0x00766d8c` excl. (956 B / `0x3BC`) | Epilogue dual `C2 0C 00` ends at `0x00766d8c`; table follows | **High** |
| ABI thiscall; stack path/mode/attrs; **`RET 0x0C`** | Dual epilogues fail (`83 C8 FF`) and success (`33 C0`); both `C2 0C 00` | **High** |
| Returns **0** / **`0xFFFFFFFF`** (not HANDLE) | Decomp + epilogue bytes | **High** |
| Mode @ `this+4`; HANDLE @ `this+8` | Decomp stores; entry `89 41 04` | **High** |
| Mode 0 → fail without CreateFile | Table[0] = `0x00766d6e` → `OR EAX,-1; RET 0x0C` | **High** |
| Mode 1 → access `0x20001`, disp 3 | `B8 01 00 02 00` at case1 | **High** |
| Mode 2 → access `0x20006`, disp 3 | Case2 lands mid case6 OR → `0x20006`; default disp 3 | **High** |
| Mode 3 → access `0x20007`, disp 3 | `B8 07 00 02 00` | **High** |
| Mode 6 → access `0x20006`, **CREATE_ALWAYS (2)** | `B9 02 00 00 00` then OR access | **High** |
| Modes 4/5 → access 0, OPEN_EXISTING | Table[4]=table[5]=`0x00766cea` (CreateFile setup; EAX still 0) | **High** |
| Share always `FILE_SHARE_READ` (1) | Decomp `CreateFileA(...,1,...)`; bytes `6A 01` before call | **High** |
| Quality gate `FUN_007a69d0()->+0x2c` | Live decomp | **High** |
| Remap only `.ogg` / `.dds` | Live decomp + string plates | **High** |
| Quality 1→`_FR`, 2→`_DE`, 3→`_UK` | Decomp writes `DAT_00a9d99c` / `998` / `9a0`; memory layout matches | **High** |
| Fail log plate `stoFileOSFile.cpp` line `0xB9` level 2 | String + decomp | **High** |
| Callers 10 / 14 sites | Live callers + xrefs | **High** |
| fopen is **probe only** | fopen/fclose before path swap; CreateFile is real open | **High** |
| Dual A/B **accept-with-gaps** | Justified: method demangle + quality singleton still open | **High** |

### Gaps (remaining / refined)

| Gap | Notes |
|---|---|
| Product C++ method demangle (`Open` vs other) | Still open; class plate Confirmed via path string only |
| `FUN_007a69d0` quality field product plate | Nested unowned; gate offset `+0x2c` sealed, product name not |
| **5th DDS suffix table entry** | Report left open (**Med**). **This ADV closes the string content:** pointer `0x00a1419b` is an **empty C-string** (suffix-less `.dds` quality try). Intentional last table slot; not a broken pointer. |
| Modes **>6** | Same as 4/5: `ja` past switch → CreateFile with access 0. Report matrix omits `>6` (minor documentation gap, not wrong for 4/5). |
| Clean quality remap body | `stoFileOSFile_Open.cpp` stubs remap as comments; acceptable for accept-with-gaps but not bit-exact |
| Runtime / bit-exact / differential | Still open |

### Adversarial attacks (this pass)

| Attack | Result |
|---|---|
| fopen is the open API | **Falsified** (probe only) |
| Returns HANDLE in EAX | **Falsified** (0/-1; HANDLE@+8) |
| Mode 6 is read / mode 1 is write | **Falsified** (access + caller patterns) |
| Bare `C3` / `RET 4` | **Falsified** (dual `C2 0C 00`) |
| Always remaps paths | **Falsified** (quality + ext gate) |
| Class not stoFileOSFile | **Falsified** (log path Confirmed) |
| Modes 4/5 are valid special open modes | **Weakened** — reach CreateFile with access 0 → fail → -1 |

### Unit verdict

**PASS** — dual **accept-with-gaps** stands. No material contradiction with live decompile / memory / xrefs. Residual gaps are naming, nested quality singleton, runtime — correctly non-terminal.

---

## Unit B — `0x00431b30` StdVector_BuyN_BasicString

### Confirmations (sealed claims hold)

| Claim | Independent result | Conf |
|---|---|---|
| Body `0x00431b30`–`0x00431b82` excl. (82 B) | Full hex 82 B then `CC` pad | **High** |
| ABI ECX=vector*; stack `n`; **`RET 4`** | Entry `8B 44 24 04` / `8B F1`; dual `C2 04 00` | **High** |
| Return AL **0** if `n==0`, **1** after buy | `32 C0` / `B0 01` | **High** |
| Zero begin@+4 / end@+8 / capEnd@+0xC **without free** | Stores only; no `operator_delete` in decomp or body | **High** |
| Stride **0x1c** | `operator_new(n*0x1c)`; lea/sub/add chain in bytes | **High** |
| Max **`0x9249249`** | Imm `3D 49 92 24 09`; equals `0xFFFFFFFF/0x1c` floor | **High** |
| Throw plate `"vector<T> too long"` noreturn | Nested decomp `FUN_004540b0` + `_CxxThrowException` | **High** |
| Decomp falsely assigns throw return → `n` | Live decomp still shows `param_2 = FUN_004540b0()`; **bytes win** (noreturn) | **High** |
| After buy: begin==end (size 0), capEnd=buf+nbytes | Decomp triad stores | **High** |
| Sole caller W34-S assign `FUN_00469d10` | Live xrefs/callers | **High** |
| Dual A/B **accept-with-gaps** | Justified: product `_Buy` demangle open | **High** |

### Gaps (remaining)

| Gap | Notes |
|---|---|
| Exact MSVC product demangle for `_Buy` helper | Naming only |
| Dynamic/runtime callers beyond static xref | Only 1 static site sealed |
| Runtime / bit-exact / differential | Open |
| Clean warns leak-if-owned | Correct; not a dual defect |

### Adversarial attacks (this pass)

| Attack | Result |
|---|---|
| Free-then-realloc grow | **Falsified** (no free) |
| Constructs n live strings (size=n) | **Falsified** (begin==end) |
| POD size ≠ 0x1c | **Falsified** |
| Bare `C3` / void / pointer return | **Falsified** (RET 4, AL 0/1) |
| `FUN_004540b0` returns clamped n | **Falsified** (noreturn throw) |
| Unrelated to string vector | **Falsified** (sole assign-from caller + throw plate) |

### Unit verdict

**PASS** — dual **accept-with-gaps** stands. Sealed ABI/CF/no-free/stride/max/throw match live evidence. Product demangle residual is naming-only.

---

## Cross-unit / package integrity

| Check | Result |
|---|---|
| Report file list complete on disk | **Yes** (raw, annotated, clean, twin, function, A, B, scratch) |
| A ≡ B dual agreement | Both units dual-agree **accept-with-gaps** |
| Report “terminal coverage false” | Correct (no runtime/diff) |
| Port notes (AutoCore impact) | Match sealed contracts; buy “do not free / empty dest” hazard correctly called out |
| W34-S residual nested buy closed | **Yes** (this unit owns buy plate) |
| Nested open plate for FS/pack callers | **Yes** (mode 1/6 matrix sealed here) |

### Minor report nits (non-failing)

1. Mode matrix should optionally note **mode >6** same as 4/5 (access 0 → CreateFile fail).
2. 5th DDS table string can be upgraded from open → **empty string** (this ADV).
3. Clean open quality-remap is abbreviated vs full image string rebuild — already implied by gaps; do not treat clean as bit-exact.

---

## Final verdict

| Unit | Dual claim | ADV result |
|---|---|---|
| `aa_007669d0` stoFileOSFile_Open | accept-with-gaps | **PASS** (accept-with-gaps affirmed) |
| `aa_00431b30` StdVector_BuyN_BasicString | accept-with-gaps | **PASS** (accept-with-gaps affirmed) |
| **Package W37-E** | dual complete | **PASS** |

No fail conditions: no ABI error, no mode-matrix inversion, no false free on buy, no missing dual artifacts, no overclaim of runtime/bit-exact.

**ADV outcome: PASS** for both units and the W37-E dual package.
